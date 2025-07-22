/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:40:08 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/21 22:48:41 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_all_reps_done(t_philo *philo, t_bool *alive);
static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print, t_bool *liv);

void	*checker_life(void *checker_arg)
{
	int				i;
	t_bool			still_alive;
	t_checker		*checker;
	pthread_mutex_t	*print;
	t_philo			*philo;

	checker = (t_checker *)checker_arg;
	philo = checker->philo;
	print = &philo->mutex.print_lock;
	still_alive = TRUE;
	while (still_alive)
	{
		i = 0;
		while (i < philo->parsing.nb_philo && still_alive)
		{
			if (philo->parsing.is_rep && is_all_reps_done(checker->philo, &still_alive))
				break;
			if (is_dead(&philo->thread[i], print, &still_alive))
				break;
			i++;
		}
		usleep(1000);
		if (still_alive == FALSE)
			detach_all(checker->philo);
	}
	return (NULL);
}

static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print, t_bool *live)
{
	long	now;
	long	timestamp;
	long	last_eaten;
	long	time_to_die;
	if (!thread || !thread->philo)
		return (FALSE);
	put("1");
	now = get_current_time();
	time_to_die = (long)thread->philo->parsing.time_die;
	last_eaten = thread->last_eaten;
	if ((now - last_eaten) > time_to_die)
	{
		timestamp = now - thread->start_time;
		pthread_mutex_lock(print);
		printf("%lu %d is dead\n", timestamp, thread->philo_number);
		*live = FALSE;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	is_all_reps_done(t_philo *philo, t_bool *alive)
{
	int	i;

	i = 0;
	while (i < philo->parsing.nb_philo)
	{
		if (philo->thread[i].rep > 0)
		{
			*alive = FALSE;
			return (FALSE);
		}
		i++;
	}
	pthread_mutex_lock(&philo->mutex.print_lock);
	return (TRUE);
}

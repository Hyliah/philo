/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:40:08 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/26 00:44:48 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		change_still_running(t_checker *checker);
static t_bool	is_all_reps_done(t_philo *philo, t_bool *alive);
static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print, t_bool *liv);

void	*checker_life(void *checker_arg)
{
	int				i;
	t_bool			still_alive;
	t_checker		*checker;
	pthread_mutex_t	*print;

	checker = (t_checker *)checker_arg;
	print = &checker->philo->mutex.print_lock;
	still_alive = TRUE;
	wait_start_program(checker->start_time);
	while (still_alive)
	{
		i = 0;
		while (i < checker->philo->parsing.nb_philo && still_alive)
		{
			if (checker->philo->parsing.is_rep
				&& is_all_reps_done(checker->philo, &still_alive))
				break ;
			if (is_dead(&checker->philo->thread[i], print, &still_alive))
				break ;
			i++;
		}
	}
	change_still_running(checker);
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
	now = get_current_time();
	pthread_mutex_lock(thread->data_access);
	time_to_die = (long)thread->philo->parsing.time_die;
	last_eaten = thread->last_eaten;
	pthread_mutex_unlock(thread->data_access);
	if ((now - last_eaten) > time_to_die)
	{
		pthread_mutex_lock(thread->data_access);
		timestamp = now - thread->start_time;
		pthread_mutex_unlock(thread->data_access);
		pthread_mutex_lock(print);
		printf("%lu %d died\n", timestamp, thread->philo_number);
		*live = FALSE;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	is_all_reps_done(t_philo *philo, t_bool *alive)
{
	int	i;
	int	rep;

	i = 0;
	while (i < philo->parsing.nb_philo)
	{
		pthread_mutex_lock(philo->thread[i].data_access);
		rep = philo->thread[i].rep;
		pthread_mutex_unlock(philo->thread[i].data_access);
		if (rep > 0)
		{
			*alive = FALSE;
			return (FALSE);
		}
		i++;
	}
	pthread_mutex_lock(&philo->mutex.print_lock);
	return (TRUE);
}

static void	change_still_running(t_checker *checker)
{
	pthread_mutex_lock(checker->data_access);
	checker->still_running = FALSE;
	pthread_mutex_unlock(checker->data_access);
}

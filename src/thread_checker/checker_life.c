/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:40:08 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/30 22:26:53 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		change_still_running(t_checker *checker);
static t_bool	is_all_reps_done(t_philo *philo);
static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print);

void	*checker_life(void *checker_arg)
{
	int				i;
	t_checker		*checker;
	pthread_mutex_t	*print;

	checker = (t_checker *)checker_arg;
	print = &checker->philo->mutex.print_lock;
	wait_start_program(checker->philo->start_time);
	while (is_running(checker->philo))
	{
		i = 0;
		while (i < checker->philo->parsing.nb_philo)
		{
			if (is_dead(&checker->philo->thread[i], print) ||
				is_all_reps_done(checker->philo))
				break ;
			i++;
		}
		usleep(500);
	}
	return (NULL);
}

static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print)
{
	long	now;
	long	timestamp;
	long	last_eaten;
	long	time_to_die;

	if (!thread || !thread->philo)
		return (FALSE);
	now = get_current_time();
	pthread_mutex_lock(&thread->philo->checker.mutex_eaten);
	time_to_die = (long)thread->philo->parsing.time_die;
	last_eaten = thread->last_eaten;
	pthread_mutex_unlock(&thread->philo->checker.mutex_eaten);
	if ((now - last_eaten) > time_to_die)
	{
		timestamp = now - thread->philo->start_time;
		printf("%lu %d died\n", timestamp, thread->philo_number); //mettre message
		change_still_running(&thread->philo->checker);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	is_all_reps_done(t_philo *philo)
{
	int		i;
	int		rep;

	i = 0;
	if (philo->parsing.is_rep == FALSE)
		return (FALSE);
	while (i < philo->parsing.nb_philo)
	{
		pthread_mutex_lock(&philo->checker.mutex_running);
		rep = philo->thread[i].rep;
		pthread_mutex_unlock(&philo->checker.mutex_running);
		if (rep < philo->parsing.rep)
			return (FALSE);
		i++;
	}
	change_still_running(&philo->checker);
	return (TRUE);
}

static void	change_still_running(t_checker *checker)
{
	pthread_mutex_lock(&checker->mutex_running);
	checker->still_running = FALSE;
	pthread_mutex_unlock(&checker->mutex_running);
}

t_bool	is_running(t_philo *philo)
{
	t_bool	is_running;

	pthread_mutex_lock(&philo->checker.mutex_running);
	is_running = philo->checker.still_running;
	pthread_mutex_unlock(&philo->checker.mutex_running);
	return (is_running);
}

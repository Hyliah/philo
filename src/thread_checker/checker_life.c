/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:40:08 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/27 16:27:11 by hlichten         ###   ########.fr       */
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
	wait_start_program(checker->start_time);
	checker->still_running = TRUE;
	while (checker->still_running)
	{
		i = 0;
		while (i < checker->philo->parsing.nb_philo && checker->still_running)
		{
			if (checker->philo->parsing.is_rep
				&& is_all_reps_done(checker->philo))
				break ;
			if (is_dead(&checker->philo->thread[i], print))
				break ;
			i++;
		}
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
	pthread_mutex_lock(&thread->data_access);
	time_to_die = (long)thread->philo->parsing.time_die;
	last_eaten = thread->last_eaten;
	pthread_mutex_unlock(&thread->data_access);
	if ((now - last_eaten) > time_to_die)
	{
		change_still_running(&thread->philo->checker);
		pthread_mutex_lock(&thread->data_access);
		timestamp = now - thread->start_time;
		pthread_mutex_unlock(&thread->data_access);
		pthread_mutex_lock(print);
		printf("%lu %d died\n", timestamp, thread->philo_number);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	is_all_reps_done(t_philo *philo)
{
	int	i;
	int	rep;

	i = 0;
	while (i < philo->parsing.nb_philo)
	{
		pthread_mutex_lock(&philo->thread[i].data_access);
		rep = philo->thread[i].rep;
		pthread_mutex_unlock(&philo->thread[i].data_access);
		if (rep > 0)
			return (FALSE);
		i++;
	}
	change_still_running(&philo->checker);
	pthread_mutex_lock(&philo->mutex.print_lock);
	return (TRUE);
}

t_bool	is_running(t_philo *philo)
{
	pthread_mutex_lock(&philo->checker.mutex_running);
	if (philo->checker.still_running == FALSE)
	{
		pthread_mutex_unlock(&philo->checker.mutex_running);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo->checker.mutex_running);
	return (TRUE);
}

static void	change_still_running(t_checker *checker)
{
	pthread_mutex_lock(&checker->mutex_running);
	checker->still_running = FALSE;
	pthread_mutex_unlock(&checker->mutex_running);
}

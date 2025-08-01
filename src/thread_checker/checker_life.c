/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:40:08 by hlichten          #+#    #+#             */
/*   Updated: 2025/08/01 18:35:26 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		change_still_running(t_checker *checker);
static void		is_all_reps_done(t_thread *thread, t_bool *all_ate);
static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print);

void	*checker_life(void *checker_arg)
{
	int				i;
	t_checker		*checker;
	pthread_mutex_t	*print;
	t_bool			all_ate;

	checker = (t_checker *)checker_arg;
	print = &checker->philo->mutex.print_lock;
	wait_start_program(checker->philo->start_time);
	while (is_running(checker->philo))
	{
		all_ate = TRUE;
		i = 0;
		while (i < checker->philo->parsing.nb_philo)
		{
			if (is_dead(&checker->philo->thread[i], print))
				break ;
			is_all_reps_done(&checker->philo->thread[i], &all_ate);
			i++;
		}
		if (all_ate)
			change_still_running(checker);
		secure_usleep(500, checker->philo);
	}
	return (NULL);
}

static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print)
{
	long	now;
	long	last_eaten;
	long	time_to_die;

	if (!thread || !thread->philo)
		return (FALSE);
	now = get_current_time();
	pthread_mutex_lock(&thread->mutex_eat);
	time_to_die = (long)thread->philo->parsing.time_die;
	pthread_mutex_unlock(&thread->mutex_eat);
	last_eaten = thread->last_eaten;
	if ((now - last_eaten) > time_to_die)
	{
		change_still_running(&thread->philo->checker);
		print_msg(thread, print, "died", TRUE);
		return (TRUE);
	}
	return (FALSE);
}

static void	is_all_reps_done(t_thread *thread, t_bool *all_ate)
{
	int		rep;

	if (thread->philo->parsing.is_rep == FALSE)
		*all_ate = FALSE;
	pthread_mutex_lock(&thread->mutex_eat);
	rep = thread->rep;
	pthread_mutex_unlock(&thread->mutex_eat);
	if (rep < thread->philo->parsing.rep)
		*all_ate = FALSE;
}

static void	change_still_running(t_checker *checker)
{
	pthread_mutex_lock(&checker->mutex_running);
	checker->still_running = FALSE;
	pthread_mutex_unlock(&checker->mutex_running);
}

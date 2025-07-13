/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:02:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/13 19:35:15 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// pour l utilisation de pthread_join, a voir ce que j en fait
static void		action_eat(t_thread *thread, pthread_mutex_t *print, int *rep);
static void		action_sleeping(t_thread *thread, pthread_mutex_t *print);
static void		print_message(t_thread *thread, pthread_mutex_t *print,
					char *message, int timestamp);
static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print, int reps);

void	*philo_life(void *thread_arg)
{
	t_thread		*thread;
	pthread_mutex_t	*print;
	int				reps;
	long			time;
	
	
	thread = (t_thread *)thread_arg;
	reps = thread->philo->parsing.rep;
	print = &thread->philo->mutex.print_lock;
	//get_current_time(thread->philo);
	while (1)
	{
		if (is_dead(thread, print, reps) == TRUE)
			break ;
		action_eat(thread, print, &reps);
		if (thread->philo->parsing.is_rep == TRUE && reps == 0)
			break ;
		action_sleeping(thread, print);
		time = thread->start_time -  get_current_time();
		print_message (thread, print, "is thinking", time);
	}
	return (NULL);
}

static void	action_eat(t_thread *thread, pthread_mutex_t *print, int *rep)
{
	unsigned long	time;
	
	time = thread->start_time - get_current_time();
	if (thread->is_odd)
	{
		pthread_mutex_lock(thread->fork_right);
		pthread_mutex_lock(thread->fork_left);
		print_message(thread, print, "has taken a fork", time);
	}
	else
	{
		pthread_mutex_lock(thread->fork_left);
		pthread_mutex_lock(thread->fork_right);
		print_message(thread, print, "has taken a fork", time);
	}
	print_message(thread, print, "is eating", time);
	usleep(thread->philo->parsing.time_eat * 1000);
	if (thread->philo->parsing.is_rep == TRUE)
		(*rep)--;
	pthread_mutex_unlock(thread->fork_left);
	pthread_mutex_unlock(thread->fork_right);
}

static void	action_sleeping(t_thread *thread, pthread_mutex_t *print)
{
	unsigned long	time;
	
	time = thread->start_time -  get_current_time();
	print_message(thread, print, "is sleeping", time);
	usleep(thread->philo->parsing.time_sleep * 1000);
}

static void	print_message(t_thread *thread, pthread_mutex_t *print,
			char *message, int timestamp)
{
	pthread_mutex_lock(print);
	printf("%d %d %s\n", timestamp, thread->philo_number, message);
	pthread_mutex_unlock(print);
}

static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print, int reps)
{
	if (thread->philo->parsing.is_rep == TRUE)
	{
		if (reps == 0)
			return (TRUE);
	}
	else
	{
		print_message(thread, print, "died", 0);
		// en cours 
	}
	return (FALSE);
}

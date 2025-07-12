/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:02:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/12 20:41:13 by hlichten         ###   ########.fr       */
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

	thread = (t_thread *)thread_arg;
	reps = thread->philo->parsing.rep;
	print = &thread->philo->mutex.print_lock;
	while (1)
	{
		if (is_dead(thread, print, reps) == TRUE)
			break ;
		action_eat(thread, print, &reps);
		if (thread->philo->parsing.is_rep == TRUE && reps == 0)
			break ;
		action_sleeping(thread, print);
		print_message (thread, print, "is thinking", 0);
	}
	return (NULL);
}

static void	action_eat(t_thread *thread, pthread_mutex_t *print, int *rep)
{
	if (thread->is_odd)
	{
		pthread_mutex_lock(thread->fork_right);
		pthread_mutex_lock(thread->fork_left);
		print_message(thread, print, "has taken a fork", 0);
	}
	else
	{
		pthread_mutex_lock(thread->fork_left);
		pthread_mutex_lock(thread->fork_right);
		print_message(thread, print, "has taken a fork", 0);
	}
	print_message(thread, print, "is eating", 0);
	usleep(thread->philo->parsing.time_eat * 1000);
	if (thread->philo->parsing.is_rep == TRUE)
		(*rep)--;
	pthread_mutex_unlock(thread->fork_left);
	pthread_mutex_unlock(thread->fork_right);
}

static void	action_sleeping(t_thread *thread, pthread_mutex_t *print)
{
	print_message(thread, print, "is sleeping", 0);
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

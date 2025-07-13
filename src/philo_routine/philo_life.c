/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:02:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/13 23:58:43 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static void		action_eat(t_thread *thread, pthread_mutex_t *print, int *rep);
static void		action_sleeping(t_thread *thread, pthread_mutex_t *print);
static void		print_msg(t_thread *thread, pthread_mutex_t *print, char *msg);
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
		print_msg(thread, print, "is thinking");
	}
	return (NULL);
}

static void	action_eat(t_thread *thread, pthread_mutex_t *print, int *rep)
{
	unsigned long	now;

	now = get_current_time();
	if (thread->is_odd)
	{
		pthread_mutex_lock(thread->fork_right);
		print_msg(thread, print, "has taken a fork");
		pthread_mutex_lock(thread->fork_left);
		print_msg(thread, print, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(thread->fork_left);
		print_msg(thread, print, "has taken a fork");
		pthread_mutex_lock(thread->fork_right);
		print_msg(thread, print, "has taken a fork");
	}
	print_msg(thread, print, "is eating");
	thread->last_eaten = now;
	usleep(thread->philo->parsing.time_eat * 1000);
	if (thread->philo->parsing.is_rep == TRUE)
		(*rep)--;
	pthread_mutex_unlock(thread->fork_left);
	pthread_mutex_unlock(thread->fork_right);
}

static void	action_sleeping(t_thread *thread, pthread_mutex_t *print)
{
	print_msg(thread, print, "is sleeping");
	usleep(thread->philo->parsing.time_sleep * 1000);
}

static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print, int reps)
{
	unsigned long	now;

	now = get_current_time();
	if ((now - thread->last_eaten) > (unsigned long)thread->philo->parsing.time_die)
	{
		print_msg(thread, print, "died");
		return (TRUE);
	}
	if (thread->philo->parsing.is_rep == TRUE && reps == 0)
		return (TRUE);
	return (FALSE);
}

static void	print_msg(t_thread *thread, pthread_mutex_t *print, char *msg)
{
	unsigned long	timestamp;

	timestamp = get_current_time() - thread->start_time;
	pthread_mutex_lock(print);
	printf("%lu %d %s\n", timestamp, thread->philo_number, msg);
	pthread_mutex_unlock(print);
}

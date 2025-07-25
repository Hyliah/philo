/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:02:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/26 00:39:52 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_eat(t_thread *thread, pthread_mutex_t *print);
static void	lock_fork_msg(t_thread *thread, pthread_mutex_t *print);
static void	action_sleeping(t_thread *thread, pthread_mutex_t *print);
static void	print_msg(t_thread *thread, pthread_mutex_t *print, char *msg);

void	*philo_life(void *thread_arg)
{
	t_thread		*thread;
	pthread_mutex_t	*print;

	thread = (t_thread *)thread_arg;
	print = &thread->philo->mutex.print_lock;
	wait_start_program(thread->start_time);
	while (1)
	{
		action_eat(thread, print);
		action_sleeping(thread, print);
		print_msg(thread, print, "is thinking");
		pthread_mutex_lock(thread->philo->checker.data_access);
		if (thread->philo->checker.still_running == FALSE)
		{
			pthread_mutex_unlock(thread->philo->checker.data_access);
			break;
		}
		pthread_mutex_unlock(thread->philo->checker.data_access);
	}
	return (NULL);
}

static void	action_eat(t_thread *thread, pthread_mutex_t *print)
{
	long	now;
	long	time_eat;

	now = get_current_time();
	lock_fork_msg(thread, print);
	print_msg(thread, print, "is eating");
	pthread_mutex_lock(thread->data_access);
	thread->last_eaten = now;
	thread->rep--;
	time_eat = thread->philo->parsing.time_eat;
	pthread_mutex_unlock(thread->data_access);
	secure_usleep(time_eat);
	pthread_mutex_unlock(thread->fork_left);
	pthread_mutex_unlock(thread->fork_right);
}

static void	lock_fork_msg(t_thread *thread, pthread_mutex_t *print)
{
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
}

static void	action_sleeping(t_thread *thread, pthread_mutex_t *print)
{
	print_msg(thread, print, "is sleeping");
	secure_usleep(thread->philo->parsing.time_sleep);
}

static void	print_msg(t_thread *thread, pthread_mutex_t *print, char *msg)
{
	long	timestamp;

	pthread_mutex_lock(thread->data_access);
	timestamp = get_current_time() - thread->start_time;
	pthread_mutex_unlock(thread->data_access);
	pthread_mutex_lock(print);
	printf("%lu %d %s\n", timestamp, thread->philo_number, msg);
	pthread_mutex_unlock(print);
}

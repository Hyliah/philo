/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:02:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/30 22:52:42 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_eat(t_thread *thread, pthread_mutex_t *print);
static void	lock_fork_msg(t_thread *thread, pthread_mutex_t *print);
static void	action_sleep(t_thread *thread, pthread_mutex_t *print);

void	*philo_life(void *thread_arg)
{
	t_thread		*thread;
	pthread_mutex_t	*print;

	thread = (t_thread *)thread_arg;
	print = &thread->philo->mutex.print_lock;
	wait_start_program(thread->philo->start_time);
	while (is_running(thread->philo))
	{
		action_eat(thread, print);
		action_sleep(thread, print);
		print_msg(thread, print, "is thinking", FALSE);
		usleep(50);
	}
	return (NULL);
}

static void	action_eat(t_thread *thread, pthread_mutex_t *print)
{
	long	time_eat;

	lock_fork_msg(thread, print);
	print_msg(thread, print, "is eating", FALSE);
	pthread_mutex_lock(&thread->philo->checker.mutex_eaten);
	thread->last_eaten = get_current_time();
	time_eat = thread->philo->parsing.time_eat;
	pthread_mutex_unlock(&thread->philo->checker.mutex_eaten);
	secure_usleep(time_eat);
	if (is_running(thread->philo))
	{
		pthread_mutex_lock(&thread->philo->checker.mutex_running);
		thread->rep++;
		pthread_mutex_unlock(&thread->philo->checker.mutex_running);
	}
	pthread_mutex_unlock(thread->fork_left);
	pthread_mutex_unlock(thread->fork_right);
}

static void	lock_fork_msg(t_thread *thread, pthread_mutex_t *print)
{
	pthread_mutex_lock(thread->fork_right);
	print_msg(thread, print, "has taken a fork", FALSE);
	pthread_mutex_lock(thread->fork_left);
	print_msg(thread, print, "has taken a fork", FALSE);
}

static void	action_sleep(t_thread *thread, pthread_mutex_t *print)
{
	print_msg(thread, print, "is sleeping", FALSE);
	secure_usleep(thread->philo->parsing.time_sleep);
}

void	print_msg(t_thread *thread, pthread_mutex_t *print, char *msg, t_bool is_dead)
{
	long	timestamp;

	pthread_mutex_lock(print);
	if (is_dead)
	{
		timestamp = get_current_time() - thread->philo->start_time;
		printf("%lu %d %s\n", timestamp, thread->philo_number, msg);
		pthread_mutex_unlock(print);
		return ;
	}
	if (is_running(thread->philo) == FALSE)
	{
		pthread_mutex_unlock(print);
		return ;
	}
	timestamp = get_current_time() - thread->philo->start_time;
	printf("%lu %d %s\n", timestamp, thread->philo_number, msg);
	pthread_mutex_unlock(print);
}

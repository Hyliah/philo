/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:02:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/29 16:09:01 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_eat(t_thread *thread, pthread_mutex_t *print);
static void	lock_fork_msg(t_thread *thread, pthread_mutex_t *print);
static void	action_sleep(t_thread *thread, pthread_mutex_t *print);
static void	print_msg(t_thread *thread, pthread_mutex_t *print, char *msg);

void	*philo_life(void *thread_arg)
{
	t_thread		*thread;
	pthread_mutex_t	*print;

	thread = (t_thread *)thread_arg;
	print = &thread->philo->mutex.print_lock;
	wait_start_program(thread->philo->start_time);
	while (1)
	{
		action_eat(thread, print);
		if (is_running(thread->philo) == FALSE)
			break ;
		action_sleep(thread, print);
		if (is_running(thread->philo) == FALSE)
			break ;
		print_msg(thread, print, "is thinking");
		if (is_running(thread->philo) == FALSE)
			break ;
	}
	return (NULL);
}

static void	action_eat(t_thread *thread, pthread_mutex_t *print)
{
	long	time_eat;

	lock_fork_msg(thread, print);
	print_msg(thread, print, "is eating");
	pthread_mutex_lock(&thread->philo->checker.mutex_running);
	thread->last_eaten = get_current_time();
	if (thread->rep > 0)
		thread->rep--;
	time_eat = thread->philo->parsing.time_eat;
	pthread_mutex_unlock(&thread->philo->checker.mutex_running);
	secure_usleep(time_eat);
	pthread_mutex_unlock(thread->fork_left);
	pthread_mutex_unlock(thread->fork_right);
}

static void	lock_fork_msg(t_thread *thread, pthread_mutex_t *print)
{
	pthread_mutex_lock(thread->fork_right);
	print_msg(thread, print, "has taken a fork");
	pthread_mutex_lock(thread->fork_left);
	print_msg(thread, print, "has taken a fork");
}

static void	action_sleep(t_thread *thread, pthread_mutex_t *print)
{
	print_msg(thread, print, "is sleeping");
	secure_usleep(thread->philo->parsing.time_sleep);
}

static void	print_msg(t_thread *thread, pthread_mutex_t *print, char *msg)
{
	long	timestamp;

	if (is_running(thread->philo))
	{
		pthread_mutex_lock(print);
		timestamp = get_current_time() - thread->philo->start_time;
		printf("%lu %d %s\n", timestamp, thread->philo_number, msg);
		pthread_mutex_unlock(print);
	}
}

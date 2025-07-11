/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:02:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/11 20:46:12 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// pour l utilisation de pthread_join, a voir ce que j en fait
static void	action_eating(t_thread *thread, pthread_mutex_t *print);

void	*philo_life(void *thread_arg)
{
	t_thread		*thread;
	pthread_mutex_t	*print;

	thread = (t_thread *)thread_arg;
	print = &thread->philo->mutex.print_lock;
	pthread_mutex_lock(print);
	if (thread->is_odd == TRUE)
		printf("hello I m thread nb %d and i am odd\n", thread->philo_number);
	else
		printf("hello I m thread nb %d and i am even\n", thread->philo_number);
	//action_eating(thread, print);
	pthread_mutex_unlock(print);


	return (NULL);
}

static void	action_eating(t_thread *thread, pthread_mutex_t *print)
{
	pthread_mutex_lock(thread->fork_left);
	pthread_mutex_lock(thread->fork_right);
	pthread_mutex_lock(print);
		printf("hello I m thread nb %d and i am even\n", thread->philo_number);
	pthread_mutex_unlock(print);
	usleep(thread->philo->parsing.time_eat);
	pthread_mutex_unlock(thread->fork_left);
	pthread_mutex_unlock(thread->fork_right);
}

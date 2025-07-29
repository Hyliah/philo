/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:12:59 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/29 14:14:47 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_odd(int nb);
static void		fill_thread_struct(t_philo *philo, t_thread *thread, int i);

int	init_threads(t_philo *philo)
{
	int			i;
	int			ret ;
	int			nb_philo;
	t_thread	*threads;

	i = 0;
	threads = philo->thread;
	nb_philo = philo->parsing.nb_philo;
	while (i < nb_philo)
	{
		init_mutex_data_thread(&threads[i]);
		fill_thread_struct(philo, &threads[i], i);
		ret = pthread_create(&threads[i].philo_th, NULL, philo_life, &threads[i]);
		if (ret)
		{
			printf("Error: failed to join create %d (errno: %d)\n", i, ret);
			return (ret);
		}
		i++;
	}
	return (0);
}

static void	fill_thread_struct(t_philo *philo, t_thread *thread, int i)
{
	int	nb_philo;

	nb_philo = philo->parsing.nb_philo;
	thread->philo = philo;
	thread->philo_number = i + 1;
	thread->rep = philo->parsing.rep;
	if (is_odd(i + 1))
	{
		thread->fork_left = &philo->mutex.forks[i];
		thread->fork_right = &philo->mutex.forks[(i + 1) % nb_philo];
	}
	else
	{
		thread->fork_left = &philo->mutex.forks[(i + 1) % nb_philo];
		thread->fork_right = &philo->mutex.forks[i];
	}
	thread->last_eaten = philo->start_time;
}

static t_bool	is_odd(int nb)
{
	if (nb % 2 != 0)
		return (TRUE);
	return (FALSE);
}

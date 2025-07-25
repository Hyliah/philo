/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:12:59 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/25 19:25:05 by hlichten         ###   ########.fr       */
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
	t_thread	*thread;

	i = 0;
	thread = philo->thread;
	nb_philo = philo->parsing.nb_philo;
	while (i < nb_philo)
	{
		fill_thread_struct(philo, &thread[i], i);
		ret = pthread_create(&thread[i].philo_th, NULL, philo_life, &thread[i]);
		if (ret)
		{
			printf("Error: failed to join create %d (errno: %d)\n", i, ret);
			return (ret);
		}
		i++;
	}
	return (0);
}

static t_bool	is_odd(int nb)
{
	if (nb % 2 != 0)
		return (TRUE);
	return (FALSE);
}

static void	fill_thread_struct(t_philo *philo, t_thread *thread, int i)
{
	int	nb_philo;

	nb_philo = philo->parsing.nb_philo;
	thread->philo = philo;
	thread->philo_number = i + 1;
	thread->is_odd = is_odd(i + 1);
	thread->rep = philo->parsing.rep;
	thread->data_access = &philo->mutex.data_accesses[i];
	thread->fork_left = &philo->mutex.forks[i];
	thread->fork_right = &philo->mutex.forks[(i + 1) % nb_philo];
	thread->start_time = start_program(philo);
	thread->last_eaten = start_program(philo);
}

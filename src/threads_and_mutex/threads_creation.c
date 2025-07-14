/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:12:59 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/14 15:32:26 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_odd(int nb);

int	init_threads(t_philo *philo, t_thread *thread)
{
	int	i;
	int	ret ;
	int	nb_philo;

	i = 0;
	nb_philo = philo->parsing.nb_philo;
	while (i < nb_philo)
	{
		thread[i].philo = philo;
		thread[i].philo_number = i + 1;
		thread[i].is_odd = is_odd(i + 1);
		thread[i].fork_left = &philo->mutex.forks[i];
		thread[i].fork_right = &philo->mutex.forks[(i + 1) % nb_philo];
		thread[i].start_time = get_current_time();
		thread[i].last_eaten = get_current_time();
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

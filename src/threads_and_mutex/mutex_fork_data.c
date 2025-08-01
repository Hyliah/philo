/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fork_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:42:49 by hlichten          #+#    #+#             */
/*   Updated: 2025/08/01 18:34:55 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mid_init(t_philo *philo, int i);

t_bool	malloc_mutex_fork(t_philo *philo)
{
	int	i;
	int	nb_philo;

	nb_philo = philo->parsing.nb_philo;
	philo->mutex.forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!philo->mutex.forks)
		return (unfructuous_malloc(philo), FALSE);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&philo->mutex.forks[i], NULL) != 0)
			return (destroy_mid_init(philo, i), FALSE);
		i++;
	}
	return (TRUE);
}

static void	destroy_mid_init(t_philo *philo, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&philo->mutex.forks[i]);
		i--;
	}
	free(philo->mutex.forks);
}

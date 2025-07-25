/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fork_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:42:49 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/25 23:56:46 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return (FALSE); // faire une fonction qui va free au milieu iykyk
		i++;
	}
	return (TRUE);
}

t_bool	malloc_mutex_data_thread(t_philo *philo)
{
	int	i;
	int	nb_philo;

	nb_philo = philo->parsing.nb_philo;
	philo->mutex.data_accesses = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!philo->mutex.data_accesses)
		return (unfructuous_malloc(philo), FALSE);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&philo->mutex.data_accesses[i], NULL) != 0)
			return (FALSE); // faire une fonction qui va free au milieu iykyk
		i++;
	}
	return (TRUE);
}

t_bool	malloc_mutex_data_checker(t_philo *philo)
{
	philo->checker.data_access = malloc(sizeof(pthread_mutex_t));
	if (!philo->checker.data_access)
		return (unfructuous_malloc(philo), FALSE);
	if (pthread_mutex_init(philo->checker.data_access, NULL) != 0)
			return (FALSE);
	return (TRUE);
}

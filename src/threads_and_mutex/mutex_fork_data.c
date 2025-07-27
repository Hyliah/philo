/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fork_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:42:49 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/27 20:57:45 by hlichten         ###   ########.fr       */
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

t_bool	init_mutex_data_thread(t_thread *thread)
{
	if (pthread_mutex_init(&thread->data_access, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	init_mutex_data_checker(t_philo *philo)
{
	if (pthread_mutex_init(&philo->checker.mutex_running, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

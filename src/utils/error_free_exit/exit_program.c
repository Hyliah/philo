/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:19:06 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/26 00:42:10 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_program(t_philo *philo)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(philo->checker.data_access);
		if (philo->checker.still_running == FALSE)
		{
			pthread_mutex_unlock(philo->checker.data_access);
			break;
		}
		pthread_mutex_unlock(philo->checker.data_access);
		usleep(100);
	}
	join_threads(philo, philo->thread, philo->checker);
	pthread_mutex_destroy(philo->checker.data_access);
	pthread_mutex_destroy(&philo->mutex.print_lock);
	i = 0;
	while (i < philo->parsing.nb_philo)
		pthread_mutex_destroy(&philo->mutex.data_accesses[i++]);
	i = 0;
	while (i < philo->parsing.nb_philo)
		pthread_mutex_destroy(&philo->mutex.forks[i++]);
}

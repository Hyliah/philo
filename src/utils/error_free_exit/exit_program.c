/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:19:06 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/27 15:02:34 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	exit_program(t_philo *philo)
// {
// 	int	i;

// 	while (1)
// 	{
// 		pthread_mutex_lock(philo->checker.data_access);
// 		if (philo->checker.still_running == FALSE)
// 		{
// 			pthread_mutex_unlock(philo->checker.data_access);
// 			break ;
// 		}
// 		pthread_mutex_unlock(philo->checker.data_access);
// 		usleep(100);
// 	}
// 	join_threads(philo, philo->thread, philo->checker);
// 	pthread_mutex_destroy(philo->checker.data_access);
// 	pthread_mutex_destroy(&philo->mutex.print_lock);
// 	i = 0;
// 	while (i < philo->parsing.nb_philo)
// 		pthread_mutex_destroy(&philo->mutex.data_accesses[i++]);
// 	i = 0;
// 	while (i < philo->parsing.nb_philo)
// 		pthread_mutex_destroy(&philo->mutex.forks[i++]);
// }

void	exit_program(t_philo *philo)
{
	int	i;

	// while (1)
	// {
	// 	pthread_mutex_lock(&philo->checker.mutex_running);
	// 	if (philo->checker.still_running == FALSE)
	// 	{
	// 		pthread_mutex_unlock(&philo->checker.mutex_running);
	// 		break ;
	// 	}
	// 	pthread_mutex_unlock(&philo->checker.mutex_running);
	// 	usleep(100);
	// }
	join_threads(philo);
	pthread_mutex_destroy(&philo->checker.mutex_running);
	pthread_mutex_unlock(&philo->mutex.print_lock);
	pthread_mutex_destroy(&philo->mutex.print_lock);
	i = 0;
	while (i < philo->parsing.nb_philo)
		pthread_mutex_destroy(&philo->mutex.forks[i++]); //gerer que les forks soit unlock
	free(philo->mutex.forks);
	free(philo->thread);
}

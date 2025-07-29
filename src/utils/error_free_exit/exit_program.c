/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:19:06 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/29 14:57:07 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_program(t_philo *philo)
{
	int	i;

	join_threads(philo);
	pthread_mutex_lock(&philo->checker.mutex_running);
	philo->checker.is_joined = TRUE;
	pthread_mutex_unlock(&philo->checker.mutex_running);
	join_checker(philo);
	pthread_mutex_destroy(&philo->checker.mutex_running);
	pthread_mutex_destroy(&philo->mutex.print_lock);
	i = 0;
	while (i < philo->parsing.nb_philo)
		pthread_mutex_destroy(&philo->mutex.forks[i++]);
	free(philo->mutex.forks);
	free(philo->thread);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:19:06 by hlichten          #+#    #+#             */
/*   Updated: 2025/08/01 18:23:46 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_program(t_philo *philo)
{
	int	i;

	join_threads(philo);
	join_checker(philo);
	pthread_mutex_destroy(&philo->checker.mutex_running);
	pthread_mutex_destroy(&philo->mutex.print_lock);
	i = 0;
	while (i < philo->parsing.nb_philo)
	{
		pthread_mutex_destroy(&philo->thread[i].mutex_eat);
		pthread_mutex_destroy(&philo->mutex.forks[i++]);
	}
	free(philo->mutex.forks);
	free(philo->thread);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:29:25 by hlichten          #+#    #+#             */
/*   Updated: 2025/08/01 18:23:57 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo)
{
	pthread_mutex_destroy(&philo->mutex.print_lock);
	pthread_mutex_destroy(&philo->checker.mutex_running);
}

void	unfructuous_malloc(t_philo *philo)
{
	ft_putstr_fd("Malloc error : Cannot allocate memory", STDERR_FILENO);
	free_all(philo);
	exit(EXIT_FAILURE);
}

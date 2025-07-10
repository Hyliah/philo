/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:59:00 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/11 00:59:54 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo *philo)
{
	philo->parsing.rep = 0;
	philo->parsing.nb_philo = 0;
	philo->parsing.time_die = 0;
	philo->parsing.time_eat = 0;
	philo->parsing.time_sleep = 0;
	philo->parsing.is_rep = FALSE;
	philo->thread->is_odd = FALSE;
	philo->thread->philo_number = 0;
	philo->thread->philo_th = NULL;
	pthread_mutex_init(&philo->mutex.print_lock, NULL);
}

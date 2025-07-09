/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:59:00 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/09 23:05:27 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo *philo)
{
	philo->info.rep = 0;
	philo->info.nb_philo = 0;
	philo->info.time_die = 0;
	philo->info.time_eat = 0;
	philo->info.time_sleep = 0;
	philo->info.is_rep = FALSE;
}
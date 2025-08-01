/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:59:00 by hlichten          #+#    #+#             */
/*   Updated: 2025/08/01 18:23:16 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	init_mutex(t_philo *philo);

void	init_struct(t_philo *philo)
{
	philo->parsing.rep = 0;
	philo->parsing.nb_philo = 0;
	philo->parsing.time_die = 0;
	philo->parsing.time_eat = 0;
	philo->parsing.time_sleep = 0;
	philo->parsing.is_rep = FALSE;
	philo->checker.still_running = TRUE;
	init_mutex(philo);
}

static t_bool	init_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->checker.mutex_running, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&philo->mutex.print_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->checker.mutex_running);
		return (FALSE);
	}
	return (TRUE);
}

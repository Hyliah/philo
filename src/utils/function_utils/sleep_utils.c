/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:48:01 by hlichten          #+#    #+#             */
/*   Updated: 2025/08/01 16:30:28 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	secure_usleep(long time, t_philo *philo)
{
	long	finish;

	finish = get_current_time() + time;
	while (get_current_time() < finish)
	{
		if (is_running(philo) == FALSE)
			break ;
		usleep(500);
	}
}

t_bool	is_running(t_philo *philo)
{
	t_bool	is_running;

	pthread_mutex_lock(&philo->checker.mutex_running);
	is_running = philo->checker.still_running;
	pthread_mutex_unlock(&philo->checker.mutex_running);
	return (is_running);
}

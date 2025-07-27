/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:54:28 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/27 14:45:52 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		printf("issue while getting time\n");
		return (0);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	start_program(t_philo *philo)
{
	long	now;
	long	start_program;

	now = get_current_time();
	start_program = now + (((long)philo->parsing.nb_philo + 1) * 20);
	return (start_program);
}

void	wait_start_program(long start_time)
{
	while (get_current_time() < start_time)
		usleep(200);
}

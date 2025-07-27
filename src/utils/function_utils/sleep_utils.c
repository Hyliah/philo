/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:48:01 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/27 17:22:20 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	secure_usleep(long time)
{
	long	finish;

	finish = get_current_time() + time;
	while (get_current_time() < finish)
		usleep(500);
}

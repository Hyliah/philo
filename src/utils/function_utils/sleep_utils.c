/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:48:01 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/22 19:26:24 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	secure_usleep(long time)
{
	long start;
	
	start = get_current_time();
	while(1)
	{
		if((get_current_time() - start) > time)
			break;
		usleep(100);
	}
}

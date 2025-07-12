/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:32:48 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/12 20:40:23 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_philo *philo, t_thread *thread)
{
	int	i;
	int	ret;

	i = 0;
	if (!thread)
		return (4);
	while (i < philo->parsing.nb_philo)
	{
		ret = pthread_join(thread[i].philo_th, NULL);
		if (ret)
		{
			printf("Error: failed to join thread %d (errno: %d)\n", i, ret);
			return (ret);
		}
		i++;
	}
	return (0);
}

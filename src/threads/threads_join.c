/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:32:48 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/11 00:44:13 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	join_threads(t_philo *philo, t_thread *thread)
{
	int	i;

	i = 0;
	if (!thread)
		return (FALSE);
	while (i < philo->parsing.nb_philo)
	{
		if (pthread_join(thread[i].philo_th, NULL))
			return (printf("Error: failed to join thread %d\n", i), FALSE);
		i++;
	}
	return (TRUE);
}

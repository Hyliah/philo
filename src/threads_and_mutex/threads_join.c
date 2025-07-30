/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:32:48 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/30 22:25:12 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_philo *philo)
{
	int	i;
	int	ret;

	i = 0;
	while (i < philo->parsing.nb_philo)
	{
		ret = pthread_join(philo->thread[i].philo_th, NULL);
		if (ret)
		{
			printf("Error: failed to join thread %d (errno: %d)\n", i, ret);
			return (ret);
		}
		i++;
	}
	return (0);
}

int	join_checker(t_philo *philo)
{
	int	ret;

	ret = pthread_join(philo->checker.checker_th, NULL);
	if (ret)
	{
		printf("Error: failed to join checker thread (errno: %d)\n", ret);
		return (ret);
	}
	return (0);
}

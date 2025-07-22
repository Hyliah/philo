/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:32:48 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/22 17:19:05 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_philo *philo, t_thread *thread, t_checker checker)
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
	ret = pthread_join(checker.checker_th, NULL);
	if (ret)
	{
		printf("Error: failed to join thread %d (errno: %d)\n", i, ret);
		return (ret);
	}
	return (0);
}

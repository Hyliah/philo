/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:32:48 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/26 23:37:42 by hlichten         ###   ########.fr       */
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
		ret = pthread_detach(philo->thread[i].philo_th);
		if (ret)
		{
			printf("Error: failed to join thread %d (errno: %d)\n", i, ret);
			return (ret);
		}
		i++;
	}
	ret = pthread_detach(philo->checker.checker_th);
	if (ret)
	{
		printf("Error: failed to join checker thread (errno: %d)\n", ret);
		return (ret);
	}
	return (0);
}

// int	join_threads(t_philo *philo, t_thread *thread, t_checker checker)
// {
// 	int	i;
// 	int	ret;

// 	i = 0;
// 	if (!thread)
// 		return (4);
// 	while (i < philo->parsing.nb_philo)
// 	{
// 		ret = pthread_detach(thread[i].philo_th);
// 		if (ret)
// 		{
// 			printf("Error: failed to join thread %d (errno: %d)\n", i, ret);
// 			return (ret);
// 		}
// 		i++;
// 	}
// 	ret = pthread_detach(checker.checker_th);
// 	if (ret)
// 	{
// 		printf("Error: failed to join checker thread (errno: %d)\n", ret);
// 		return (ret);
// 	}
// 	return (0);
// }

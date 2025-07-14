/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_checker_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:31:37 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/14 16:26:06 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_checker(t_philo *philo, t_checker *checker)
{
	int	ret ;

	checker->philo = philo;
	checker->last_eaten = 0;
	checker->start_time = 0;
	checker->nb_philo = philo->parsing.nb_philo;
	ret = pthread_create(&checker->checker_th, NULL, philo_life, &checker);
	if (ret)
	{
		printf("Error: failed to create checker (errno: %d)\n", ret);
		return (ret);
	}
	return (0);
}

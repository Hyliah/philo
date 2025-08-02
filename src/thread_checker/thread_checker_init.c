/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_checker_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:31:37 by hlichten          #+#    #+#             */
/*   Updated: 2025/08/01 15:07:45 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_checker(t_philo *philo)
{
	int			ret;
	t_checker	*checker;

	checker = &philo->checker;
	checker->philo = philo;
	checker->nb_philo = philo->parsing.nb_philo;
	ret = pthread_create(&checker->checker_th, NULL, checker_life, checker);
	if (ret)
	{
		printf("Error: failed to create checker (errno: %d)\n", ret);
		return (ret);
	}
	return (0);
}

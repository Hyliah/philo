/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:06:28 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/27 17:35:31 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_handler(t_philo *philo)
{
	int			ret;

	philo->thread = malloc(sizeof(t_thread) * philo->parsing.nb_philo);
	if (!philo->thread)
		return (unfructuous_malloc(philo), 4);
	start_program(philo);
	ret = init_threads(philo);
	if (ret)
		return (ret);
	ret = init_checker(philo);
	if (ret)
		return (ret);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:06:28 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/26 00:43:01 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_handler(t_philo *philo)
{
	int			ret;

	philo->thread = malloc(sizeof(t_thread) * philo->parsing.nb_philo);
	if (!philo->thread)
		return (unfructuous_malloc(philo), 4);
	ret = init_threads(philo);
	if (ret)
		return (ret);
	ret = init_checker(philo);
	if (ret)
		return (ret);
	return (0);
}

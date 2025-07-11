/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:06:28 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/11 20:07:16 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_handler(t_philo *philo)
{
	int			ret;
	t_thread	*thread;

	thread = malloc(sizeof(t_thread) * philo->parsing.nb_philo);
	if (!thread)
		return (unfructuous_malloc(philo), 4);
	ret = init_threads(philo, thread);
	if (ret)
		return (ret);
	ret = join_threads(philo, thread);
	if (ret)
		return (ret);
	return (TRUE);
}

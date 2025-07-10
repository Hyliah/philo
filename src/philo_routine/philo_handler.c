/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:06:28 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/11 01:02:00 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	philo_handler(t_philo *philo)
{
	t_thread	*thread;

	thread = malloc(sizeof(t_thread) * philo->parsing.nb_philo);
	if (!thread)
		return (printf("Error: malloc failed\n"), FALSE);
	if (!init_threads(philo, thread))
		return (FALSE);
	if (!join_threads(philo, thread))
		return (FALSE);
	return (TRUE);
}

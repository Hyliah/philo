/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:06:28 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/14 16:37:07 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ATTENTION MALLOC DES THREADS ET DU CHECKER

int	philo_handler(t_philo *philo)
{
	int			ret;
	t_thread	*thread;
	t_checker	*checker;

	thread = malloc(sizeof(t_thread) * philo->parsing.nb_philo);
	if (!thread)
		return (unfructuous_malloc(philo), 4);
	checker = malloc(sizeof(t_thread));
	if (!thread)
		return (unfructuous_malloc(philo), 4);
	ret = init_threads(philo, thread);
	if (ret)
		return (ret);
	ret = init_checker(philo, checker);
	if (ret)
		return (ret);
	ret = join_threads(philo, thread, checker);
	if (ret)
		return (ret);
	return (TRUE);
}

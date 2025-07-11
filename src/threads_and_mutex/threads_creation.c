/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:12:59 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/11 19:02:37 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_odd(int nb);

// fonction qui va initialiser des structures de philo qui gardent leurs infos
// comme une sorte de liste chainee. Pas vraiment mais t as l idee
// pour l instant les infos sont : nb-> name, et le thread créé via la fonction
// peut etre il y aura le is_odd et les infos fourchettes
/* en cours */
t_bool	init_threads(t_philo *philo, t_thread *thread)
{
	int	i;

	i = 0;
	while (i < philo->parsing.nb_philo)
	{
		if (pthread_create(&thread[i].philo_th, NULL, philo_life, &thread[i]) != 0)
			return (printf("Error: failed to initiate thread %d\n", i), FALSE);
		thread[i].philo = philo;
		thread[i].philo_number = i + 1;
		thread[i].is_odd = is_odd(i + 1);
		thread[i].fork_left = &philo->mutex.forks[i];
		thread[i].fork_right = &philo->mutex.forks[(i + 1) % philo->parsing.nb_philo];
		i++;
	}
	return (TRUE);
}

static t_bool	is_odd(int nb)
{
	if (nb % 2 != 0)
		return (TRUE);
	return (FALSE);
}

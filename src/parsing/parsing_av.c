/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:55:49 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/09 23:56:25 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_av_entry(t_philo *philo, int ac, char **av)
{
	philo->info.nb_philo = ft_atoi(av[1]);
	philo->info.time_die = ft_atoi(av[2]);
	philo->info.time_eat = ft_atoi(av[3]);
	philo->info.time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		philo->info.is_rep = TRUE;
		philo->info.rep = ft_atoi(av[5]);
	}
}
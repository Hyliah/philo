/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:55:49 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/29 13:35:31 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_av_entry(t_philo *philo, int ac, char **av)
{
	philo->parsing.nb_philo = ft_atoi(av[1]);
	philo->parsing.time_die = ft_atoi(av[2]);
	philo->parsing.time_eat = ft_atoi(av[3]);
	philo->parsing.time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		philo->parsing.is_rep = TRUE;
		philo->parsing.rep = ft_atoi(av[5]);
	}
}

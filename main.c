/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:30:06 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/12 20:40:55 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int		ret;
	t_philo	philo;

	if (!is_entry_correct(ac, av))
		return (1);
	init_struct(&philo);
	parsing_av_entry(&philo, ac, av);
	if (philo.parsing.nb_philo == 1)
	{
		printf("0 1 died");
		return (1);
	}
	malloc_mutex_fork(&philo);
	ret = philo_handler(&philo);
	if (ret)
		return (1);
	return (0);
}

// fonctions autorisees : 

// memset
// printf
// malloc
// free
// write
// usleep
// gettimeofday

// pthread_create
// pthread_detach
// pthread_join

// pthread_mutex_init
// pthread_mutex_destroy
// pthread_mutex_lock
// pthread_mutex_unlock

//  timestamp_in_ms X has taken a fork
//  timestamp_in_ms X is eating
//  timestamp_in_ms X is sleeping
//  timestamp_in_ms X is thinking
//  timestamp_in_ms X died
// Replace timestamp_in_ms with the current timestamp in milliseconds 
	//and X with the philosopher numbers
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:30:06 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/26 00:45:34 by hlichten         ###   ########.fr       */
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
	malloc_mutex_fork(&philo);
	malloc_mutex_data_thread(&philo);
	ret = philo_handler(&philo);
	if (ret)
		return (1);
	exit_program(&philo);
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
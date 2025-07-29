/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:30:06 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/29 14:36:22 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int		ret;
	t_philo	philo;

	memset((void *) &philo, 0, sizeof(t_philo));
	if (!is_entry_correct(ac, av))
		return (1);
	if (is_single_thread(av))
		return (0);
	init_struct(&philo);
	parsing_av_entry(&philo, ac, av);
	malloc_mutex_fork(&philo);
	ret = philo_handler(&philo);
	if (ret)
		return (1);
	exit_program(&philo);
	return (0);
}

/*
VALGRIND

leaks :
valgrind --leak-check=full --log-file=valgrind.log 
        --show-leak-kinds=all --default-suppressions=yes ./philo 3 200 200 200

data races :
valgrind --tool=helgrind --log-file=valgrind_data.log ./philo 10 800 200 200 3
*/ 
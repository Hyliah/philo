/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:40:08 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/14 16:45:28 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(void *checker_arg)
{
	t_checker		*checker;
	pthread_mutex_t	*print;

	checker = (t_checker *)checker_arg;
	while (1)
	{
		//faire la gestion des differentes peut etre mort
	}
}

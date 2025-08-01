/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:06:28 by hlichten          #+#    #+#             */
/*   Updated: 2025/08/01 18:48:23 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	quit_clean_malloc(t_philo *philo);
static void	quit_clean_mutex(t_philo *philo, int j);

int	philo_handler(t_philo *philo)
{
	int	ret;
	int	i;

	i = 0;
	philo->thread = malloc(sizeof(t_thread) * philo->parsing.nb_philo);
	if (!philo->thread)
		return (quit_clean_malloc(philo), 4);
	start_program(philo);
	while (i < philo->parsing.nb_philo)
	{
		if (pthread_mutex_init(&philo->thread[i].mutex_eat, NULL) != 0)
			return (quit_clean_mutex(philo, i), 1);
		i++;
	}
	ret = init_threads(philo);
	if (ret)
		return (ret);
	ret = init_checker(philo);
	if (ret)
		return (ret);
	return (0);
}

static void	quit_clean_malloc(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->parsing.nb_philo)
	{
		pthread_mutex_destroy(&philo->mutex.forks[i]);
		i++;
	}
	unfructuous_malloc(philo);
	free (philo->mutex.forks);
}

static void	quit_clean_mutex(t_philo *philo, int j)
{
	int	i;

	i = 0;
	while (i < philo->parsing.nb_philo)
	{
		pthread_mutex_destroy(&philo->mutex.forks[i]);
		i++;
	}
	free (philo->mutex.forks);
	while (j > 0)
	{
		pthread_mutex_destroy(&philo->thread[j].mutex_eat);
		j--;
	}
}

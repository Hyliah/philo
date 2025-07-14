/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:40:08 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/14 23:18:47 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_all_reps_done(t_philo *philo);
static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print);

void	*philo_life(void *checker_arg)
{
	int				i;
	t_bool			still_alive;
	t_checker		*checker;
	pthread_mutex_t	*print;

	still_alive = TRUE;
	checker = (t_checker *)checker_arg;
	while (1)
	{
		i = 0;
		while (i < checker->philo->parsing.nb_philo && still_alive == TRUE)
		{
			if (is_all_reps_done(checker->philo)
				|| is_dead(&checker->philo->thread[i], print))
				still_alive = FALSE;
			i++;
		}
		if (still_alive == FALSE)
			exit_program();
	}
}

static t_bool	is_dead(t_thread *thread, pthread_mutex_t *print)
{
	unsigned long	now;

	now = get_current_time();
	if ((now - thread->last_eaten) > (unsigned long)thread->philo->parsing.time_die)
	{
		print_msg(thread, print, "died");
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	is_all_reps_done(t_philo *philo)
{
	int	i;

	i = 0;
	while (&philo->thread->philo_th[i] < philo->parsing.nb_philo)
	{
		if (philo->thread[i].rep > 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:50:20 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/14 16:18:55 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_parsing
{
	t_bool	is_rep;
	int		rep;
	int		time_eat;
	int		time_die;
	int		nb_philo;
	int		time_sleep;
}	t_parsing;

typedef struct s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
}	t_mutex;

typedef struct s_thread
{
	pthread_t		philo_th;
	t_bool			is_odd;
	int				philo_number;
	struct s_philo	*philo;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	long			start_time;
	long			last_eaten;
}	t_thread;

typedef struct s_checker
{
	struct s_philo	*philo;
	pthread_t		checker_th;
	int				nb_philo;
	long			start_time;
	long			last_eaten;
}	t_checker;

typedef struct s_philo
{
	t_parsing		parsing;
	t_thread		*thread;
	t_mutex			mutex;
}	t_philo;

#endif
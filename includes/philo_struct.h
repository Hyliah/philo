/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:50:20 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/25 15:59:05 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct s_philo t_philo;

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
	pthread_mutex_t	*data_accesses;
}	t_mutex;

typedef struct s_thread
{
	int				rep;
	int				philo_number;
	long			start_time;
	long			last_eaten;
	t_philo			*philo;
	t_bool			is_odd;
	pthread_t		philo_th;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*data_access;
}	t_thread;

typedef struct s_checker
{
	t_philo		*philo;
	pthread_t	checker_th;
	int			nb_philo;
	long		start_time;
	long		last_eaten;
}	t_checker;

typedef struct s_philo
{
	t_checker	checker;
	t_parsing	parsing;
	t_thread	*thread;
	t_mutex		mutex;
}	t_philo;

#endif
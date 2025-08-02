/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:50:20 by hlichten          #+#    #+#             */
/*   Updated: 2025/08/01 18:23:41 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct s_philo	t_philo;

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
	int				rep;
	int				philo_number;
	long			last_eaten;
	t_philo			*philo;
	pthread_t		philo_th;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}	t_thread;

typedef struct s_checker
{
	t_philo			*philo;
	pthread_t		checker_th;
	int				nb_philo;
	t_bool			still_running;
	pthread_mutex_t	mutex_running;
}	t_checker;

typedef struct s_philo
{
	t_checker	checker;
	t_parsing	parsing;
	t_thread	*thread;
	t_mutex		mutex;
	long		start_time;
}	t_philo;

#endif
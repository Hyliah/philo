/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:50:20 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/09 23:43:28 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_info
{
	t_bool  is_rep;
	int		rep;
	int		time_eat;
	int		time_die;
	int		nb_philo;
	int		time_sleep;
}	t_info;

typedef struct s_philo
{
	t_info	info;
}	t_philo;

#endif
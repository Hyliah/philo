/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:34:10 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/09 23:58:34 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNCTIONS_H
# define PHILO_FUNCTIONS_H

# include "philo.h"
/*MAIN*/
int	main(int ac, char **av);

/*PARSING*/
t_bool	is_entry_correct(int ac, char **av);
void	parsing_av_entry(t_philo *philo, int ac, char **av);

/*UTILS*/
char	*ft_itoa(int nbr);
int     ft_strlen(char *str);
int	    ft_atoi(const char *str);
void	*free_ptr(void **ptr);
void	free_all(t_philo *philo);
void	init_struct(t_philo *philo);
void	unfructuous_malloc(t_philo *philo);

#endif
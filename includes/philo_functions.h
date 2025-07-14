/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:34:10 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/14 16:33:13 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNCTIONS_H
# define PHILO_FUNCTIONS_H

# include "philo.h"
/*MAIN*/
int		main(int ac, char **av);
/*PARSING*/
t_bool	is_entry_correct(int ac, char **av);
void	parsing_av_entry(t_philo *philo, int ac, char **av);
/*THREADS & MUTEX*/
t_bool	malloc_mutex_fork(t_philo *philo);
int		init_threads(t_philo *philo, t_thread *thread);
int		join_threads(t_philo *philo, t_thread *thread, t_checker *checker);
/*PHILO_ROUTINE*/
long	get_current_time(void);
void	*philo_life(void *thread);
int		philo_handler(t_philo *philo);
/*UTILS*/
char	*ft_itoa(int nbr);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	*free_ptr(void **ptr);
void	free_all(t_philo *philo);
void	init_struct(t_philo *philo);
void	ft_putstr_fd(char *s, int fd);
void	unfructuous_malloc(t_philo *philo);
/*CHECKER*/
int		init_checker(t_philo *philo, t_checker *checker);

#endif
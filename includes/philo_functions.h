/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:34:10 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/26 23:39:35 by hlichten         ###   ########.fr       */
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
t_bool	malloc_mutex_data_thread(t_philo *philo);
t_bool	malloc_mutex_data_checker(t_philo *philo);
int		init_threads(t_philo *philo);
//int		join_threads(t_philo *philo, t_thread *thread, t_checker checker);
int		join_threads(t_philo *philo);
/*PHILO_ROUTINE*/
void	*philo_life(void *thread);
int		philo_handler(t_philo *philo);
void	*checker_life(void *checker_arg);
/*UTILS*/
char	*ft_itoa(int nbr);
long	get_current_time(void);
long	start_program(t_philo *philo);
int		ft_atoi(const char *str);
void	wait_start_program(long start_time);
void	free_all(t_philo *philo);
void	secure_usleep(long time);
void	init_struct(t_philo *philo);
void	ft_putstr_fd(char *s, int fd);
void	unfructuous_malloc(t_philo *philo);
/*CHECKER*/
int		init_checker(t_philo *philo);

void	exit_program(t_philo *philo);

#endif
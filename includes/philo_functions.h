/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:34:10 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/30 22:24:15 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNCTIONS_H
# define PHILO_FUNCTIONS_H

# include "philo.h"
/*MAIN*/
int		main(int ac, char **av);
/*PARSING*/
t_bool	is_single_thread(char **av);
t_bool	is_entry_correct(int ac, char **av);
void	parsing_av_entry(t_philo *philo, int ac, char **av);
/*THREADS & MUTEX*/
t_bool	malloc_mutex_fork(t_philo *philo);
t_bool	init_mutex_checker(t_philo *philo);
int		init_threads(t_philo *philo);
int		join_threads(t_philo *philo);
int		join_checker(t_philo *philo);
void	print_msg(t_thread *thread, pthread_mutex_t *print, char *msg);
/*PHILO_ROUTINE*/
void	*philo_life(void *thread);
int		philo_handler(t_philo *philo);
void	*checker_life(void *checker_arg);
/*UTILS*/
char	*ft_itoa(int nbr);
long	get_current_time(void);
int		ft_atoi(const char *str);
void	free_all(t_philo *philo);
void	secure_usleep(long time);
void	init_struct(t_philo *philo);
void	ft_putstr_fd(char *s, int fd);
void	start_program(t_philo *philo);
void	wait_start_program(long start_time);
void	unfructuous_malloc(t_philo *philo);
/*CHECKER*/
t_bool	is_running(t_philo *philo);
int		init_checker(t_philo *philo);
void	exit_program(t_philo *philo);

#endif
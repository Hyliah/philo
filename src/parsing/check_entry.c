/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:07:48 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/30 21:13:31 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_zero(char *av_i);
static t_bool	is_numeric(char *str);

t_bool	is_entry_correct(int ac, char **av)
{
	int	i;

	i = 1;
	if ((ac < 5) || (ac > 6))
		return (printf("please enter the right amount of parameters"), FALSE);
	while (av[i])
	{
		if (!is_numeric(av[i]))
			return (printf("please enter positive numeric arguments"), FALSE);
		if (is_zero(av[i]))
			return (printf("zero is not a valid argument"), FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	is_zero(char *av_i)
{
	int	nb;

	nb = ft_atoi(av_i);
	if (nb == 0)
		return (TRUE);
	return (FALSE);
}
static t_bool	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	is_single_thread(char **av)
{
	int	nb_thread;
	int	time_to_die;

	nb_thread = ft_atoi(av[1]);
	time_to_die = ft_atoi(av[2]);
	if (nb_thread != 1)
		return (FALSE);
	else
	{
		printf("0 1 has taken a fork\n");
		secure_usleep(time_to_die);
		printf("%d 1 died", (time_to_die + 1));
	}
	return (TRUE);
}

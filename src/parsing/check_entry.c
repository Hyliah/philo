/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:07:48 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/11 00:39:38 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_numeric(char *str);

/* 
fonction check des infos donnees pour eviter les pb
affiche un message en fonction
verifiee, all good
*/
t_bool	is_entry_correct(int ac, char **av)
{
	int	i;

	i = 1;
	if ((ac < 5) || (ac > 6))
		return (printf("please enter the right amount of parameters"), FALSE);
	while (av[i])
	{
		if (!is_numeric(av[i]))
			return (printf("please enter numeric arguments"), FALSE);
		i++;
	}
	return (TRUE);
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

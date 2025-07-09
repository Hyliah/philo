/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:39:36 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/09 23:04:23 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_nblen(int nbr);
static void	ft_putnbr(unsigned int n, char *array, int i);

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	result;

	i = 0;
	signe = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (signe * result);
}

char	*ft_itoa(int nbr)
{
	char			*str;
	int				len;
	unsigned int	n;

	len = ft_nblen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		n = nbr * -1;
		str[0] = '-';
	}
	else
		n = nbr;
	str[len] = 0;
	ft_putnbr(n, str, len);
	return (str);
}

static int	ft_nblen(int nbr)
{
	unsigned int	n;
	int				len;

	len = 1;
	if (nbr < 0)
	{
		n = nbr * -1;
		len ++;
	}
	else
		n = nbr;
	while (n > 9)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static void	ft_putnbr(unsigned int n, char *array, int i)
{
	if (n > 9)
		ft_putnbr(n / 10, array, i - 1);
	array[i - 1] = (n % 10) + '0';
}

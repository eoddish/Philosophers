/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:05:52 by eoddish           #+#    #+#             */
/*   Updated: 2021/07/22 16:35:36 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	int		i;
	char	*space;

	i = 0;
	space = "\t\n\v\f\r ";
	while (space[i])
	{
		if (c == space[i++])
			return (1);
	}
	return (0);
}

static int	ft_topower(int a, int b)
{
	int	res;

	res = 1;
	while (b--)
		res *= a;
	return (res);
}

static int	ft_atoi_overflow(int negative)
{
	if (negative)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		negative;
	int		add;

	i = 0;
	nbr = 0;
	negative = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			negative = 1;
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isdigit(*str))
	{
		add = ft_topower(10, i-- - 1) * (*str++ - '0');
		if (add > LONG_MAX - nbr)
			return (ft_atoi_overflow(negative));
		nbr += add;
	}
	if (negative)
		nbr = -nbr;
	return (nbr);
}

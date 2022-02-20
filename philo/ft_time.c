/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 21:00:24 by eoddish           #+#    #+#             */
/*   Updated: 2021/07/24 19:51:31 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(t_args *args)
{
	struct timeval	time;
	long			cur;

	gettimeofday(&time, NULL);
	cur = time.tv_sec * 1000000 + time.tv_usec;
	return ((cur - args->s_time) / 1000);
}

void	ft_usleep(long t, t_args *args)
{
	long	end;

	end = ft_time(args) + t;
	while (ft_time(args) < end)
	{
		usleep(250);
	}
}

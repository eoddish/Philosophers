/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:09:26 by eoddish           #+#    #+#             */
/*   Updated: 2021/07/24 19:48:07 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clock_2(t_args *args, int i)
{
	if (ft_time(args) - args->a->starve[i] >= args->a->ttd)
	{
		pthread_mutex_lock(&args->a->safe[i]);
		if (ft_time(args) - args->a->starve[i] >= args->a->ttd)
		{
			printf("%ld %d %s\n", ft_time(args), i + 1, "died");
			args->a->death = 1;
			i = 0;
			while (i < args->a->nof)
			{
				pthread_mutex_unlock(&args->a->mp[i]);
				pthread_mutex_unlock(&args->a->safe[i]);
				i++;
			}
			return (-1);
		}
		else
			pthread_mutex_unlock(&args->a->safe[i]);
	}
	return (0);
}

void	*ft_clock(void *pass)
{
	int		i;
	t_args	*args;

	args = (t_args *) pass;
	while (1)
	{
		i = 0;
		while (i < args->a->nof)
		{	
			if (ft_clock_2(args, i))
				break ;
			i++;
		}
		if (args->a->death)
			break ;
	}
	free(args);
	return ((void *) "hey");
}

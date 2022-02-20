/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 21:01:13 by eoddish           #+#    #+#             */
/*   Updated: 2021/07/24 20:37:12 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_thinking(t_args *args)
{
	if (args->a->death)
		return (-1);
	printf("%ld %d %s\n", ft_time(args), args->first, "is thinking");
	pthread_mutex_lock(&args->a->mp[args->first - 1]);
	if (args->a->death)
		return (-1);
	printf("%ld %d %s\n", ft_time(args), args->first, "has taken a fork");
	pthread_mutex_lock(&args->a->mp[args->first % args->a->nof]);
	if (args->a->death)
		return (-1);
	printf("%ld %d %s\n", ft_time(args), args->first, "has taken a fork");
	return (0);
}

int	ft_eating(t_args *args, int cnt)
{
	pthread_mutex_lock(&args->a->safe[args->first - 1]);
	if (args->a->death)
		return (-1);
	printf("%ld %d %s\n", ft_time(args), args->first, "is eating");
	args->a->starve[args->first - 1] = ft_time(args);
	ft_usleep(args->a->tte, args);
	pthread_mutex_unlock(&args->a->safe[args->first - 1]);
	pthread_mutex_unlock(&args->a->mp[args->first - 1]);
	pthread_mutex_unlock(&args->a->mp[args->first % args->a->nof]);
	cnt++;
	if (cnt == args->a->notefme)
		args->a->all_thd++;
	if (args->a->full && args->a->all_thd == args->a->nof)
	{
		args->a->death = 1;
		return (-1);
	}
	return (cnt);
}

void	*ft_routine(void *pass)
{
	int		cnt;
	t_args	*args;

	cnt = 0;
	args = (t_args *) pass;
	if (args->first % 2 == 0)
	{
		usleep(2000);
	}
	while (1)
	{
		if (ft_thinking(args))
			break ;
		cnt = ft_eating(args, cnt);
		if (cnt < 0)
			break ;
		if (args->a->death)
			break ;
		printf("%ld %d %s\n", ft_time(args), args->first, "is sleeping");
		ft_usleep(args->a->tts, args);
	}
	free(args);
	return ((void *)"hello");
}

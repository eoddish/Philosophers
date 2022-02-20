/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 03:43:29 by eoddish           #+#    #+#             */
/*   Updated: 2021/07/24 21:20:22 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clear(t_all *a)
{
	a->death = 1;
	usleep (a->ttd + 1);
	ft_clear_2(a);
	return (-1);
}

int	ft_init_3(t_args *args, t_all *a, int i)
{
	args = malloc (sizeof (t_args));
	if (!args)
		return (-1);
	memset(args, '\0', sizeof(t_args));
	args->first = i + 1;
	args->a = a;
	args->s_time = args->a->s_time;
	pthread_create(&((a->thd)[i]), NULL,
		ft_routine, args);
	return (0);
}

int	ft_init_2(t_all *a)
{
	int		i;
	t_args	*args;

	i = 0;
	args = 0;
	while (i < a->nof)
	{
		pthread_mutex_init(&a->mp[i], NULL);
		pthread_mutex_init(&a->safe[i++], NULL);
	}
	i = 0;
	while (i < a->nof)
	{
		if (ft_init_3(args, a, i))
			return (ft_clear(a));
		i++;
	}
	args = malloc (sizeof (t_args));
	if (!args)
		return (ft_clear(a));
	memset(args, '\0', sizeof(t_args));
	args->a = a;
	args->s_time = args->a->s_time;
	pthread_create(&((a->thd)[i]), NULL, ft_clock, args);
	return (0);
}

int	ft_init(t_all *a)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	a->s_time = time.tv_sec * 1000000 + time.tv_usec;
	a->starve = malloc(sizeof(long) * (a->nof + 1));
	memset(a->starve, '\0', sizeof(long) * (a->nof + 1));
	a->thd = malloc(sizeof(pthread_t) * (a->nof + 2));
	memset(a->thd, '\0', sizeof(pthread_t) * (a->nof + 2));
	a->mp = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (a->nof + 1));
	memset(a->mp, '\0', sizeof(pthread_mutex_t) * (a->nof + 1));
	a->safe = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (a->nof + 1));
	memset(a->safe, '\0', sizeof(pthread_mutex_t) * (a->nof + 1));
	if (!a->starve || !a->thd || !a->mp || !a->safe)
	{
		ft_clear_2(a);
		return (-1);
	}
	if (ft_init_2(a))
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:46:27 by eoddish           #+#    #+#             */
/*   Updated: 2021/07/24 21:26:05 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clear_2(t_all *a)
{
	int		i;

	i = 0;
	while (i < a->nof)
	{
		if (a->thd)
			pthread_detach(a->thd[i]);
		if (a->safe)
			pthread_mutex_destroy(&a->safe[i]);
		if (a->mp)
			pthread_mutex_destroy(&a->mp[i]);
		i++;
	}
	if (a->thd)
		pthread_detach(a->thd[i]);
	if (a->starve)
		free(a->starve);
	if (a->safe)
		free(a->safe);
	if (a->thd)
		free(a->thd);
	if (a->mp)
		free(a->mp);
	free(a);
}

int	ft_check_args(t_all *a)
{
	if ((a->full && !a->notefme) || !a->nof)
	{
		free(a);
		return (-1);
	}
	if (a->nof <= 0 || a->nof > 200
		|| a->ttd < 60 || a->tts < 60
		|| a->tte < 60 || (a->full && a->notefme < 0))
	{
		printf("%s\n", "Error: Wrong arguments");
		free(a);
		return (-1);
	}
	return (0);
}

void	ft_get_args(t_all *a, char **argv)
{
	a->nof = (long)ft_atoi(argv[1]);
	a->ttd = (long)ft_atoi(argv[2]);
	a->tte = (long)ft_atoi(argv[3]);
	a->tts = (long)ft_atoi(argv[4]);
}

int	main(int argc, char **argv)
{
	t_all	*a;

	a = malloc(sizeof(t_all));
	if (!a)
		return (-1);
	memset(a, '\0', sizeof(t_all));
	if (argc < 5 || argc > 6)
	{
		printf("%s\n", "Error: Wrong arguments");
		free (a);
		return (-1);
	}
	ft_get_args(a, argv);
	if (argc == 6)
	{
		a->full = 1;
		a->notefme = (long)ft_atoi(argv[5]);
	}
	if (ft_check_args(a))
		return (-1);
	if (ft_init(a))
		return (-1);
	ft_wait(a);
	free(a);
	return (0);
}

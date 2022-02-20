/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:05:59 by eoddish           #+#    #+#             */
/*   Updated: 2021/07/24 21:22:51 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(t_all *a)
{
	int	i;

	i = 0;
	while (i <= a->nof)
	{
		pthread_join(a->thd[i], NULL);
		i++;
	}
	i = 0;
	while (i < a->nof)
	{
		pthread_detach(a->thd[i]);
		pthread_mutex_destroy(&a->safe[i]);
		pthread_mutex_destroy(&a->mp[i]);
		i++;
	}
	pthread_detach(a->thd[i]);
	free(a->starve);
	free(a->thd);
	free(a->mp);
	free(a->safe);
}

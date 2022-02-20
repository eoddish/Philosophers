/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:03:41 by eoddish           #+#    #+#             */
/*   Updated: 2021/07/24 21:12:23 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_all
{
	long			nof;
	long			ttd;
	long			tte;
	long			tts;
	long			notefme;
	long			s_time;
	pthread_t		*thd;
	pthread_mutex_t	*mp;
	pthread_mutex_t	*safe;
	pthread_mutex_t	exit;
	int				full;
	int				all_thd;
	int				death;
	long			current;
	long			*starve;
}		t_all;

typedef struct s_args
{
	int		first;
	long	second;
	t_all	*a;
	long	s_time;
}		t_args;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_init(t_all *a);
void	*ft_routine(void *pass);
void	*ft_clock(void *pass);
void	ft_wait(t_all *a);
long	ft_time(t_args *a);
void	ft_usleep(long t, t_args *args);
void	ft_clear_2(t_all *a);

#endif

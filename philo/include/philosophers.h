/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:05:44 by dabdulka          #+#    #+#             */
/*   Updated: 2026/02/27 17:58:58 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_philo
{
	long long	*philosophers;
	long long	number_of_philosophers;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	number_of_times_each_philosopher_must_eat;
	long long	philosophers_idx;
}	t_philo;

typedef struct s_table
{
	long long *fork;
	long long fork_idx;
}	t_table;

typedef struct s_threads
{
	pthread_t thread1;
} t_threads;

long long	ft_atol(char *s);
int			ft_is_space(char c);
int		init_philos(t_philo *philo, t_table *table, char **str_arr);
#endif


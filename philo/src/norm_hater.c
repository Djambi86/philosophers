/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_hater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:18:16 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/13 21:14:45 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_is_sign(char *s, int *i)
{
	if (s[*i] == '-')
	{
		printf("Only positive numbers please!\n");
		return (0);
	}
	if (s[*i] == '+')
		(*i)++;
	return (1);
}

int	no_letters(char c)
{
	if (c < '0' || c > '9')
	{
		printf("No letters allowed!\n");
		return (0);
	}
	return (1);
}

int	is_dead_or_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_lock);
	if (philo->table->someone_died || philo->table->all_ate)
	{
		pthread_mutex_unlock(&philo->table->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->death_lock);
	return (0);
}

int	min_num_args(t_table *table)
{
	if (table->num_philos <= 1)
	{
		printf("Need atleast 2 philosophers\n");
		return (0);
	}
	if (table->time_to_die < 40 || table->time_to_eat < 40
		|| table->time_to_sleep < 40)
	{
		printf("Need atleast 40 miliseconds!\n");
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 12:00:00 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/16 00:00:00 by oai               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	should_die(t_table *table, long long time_since_meal)
{
	long long	cycle_time;

	if (time_since_meal >= table->time_to_die)
		return (1);
	if (table->num_philos % 2 == 0 || table->num_philos == 1)
		return (0);
	cycle_time = (table->time_to_eat * 2) + table->time_to_sleep;
	if (table->time_to_die < cycle_time && time_since_meal >= table->time_to_die)
		return (1);
	return (0);
}

static int	check_death(t_table *table, int i)
{
	long long	time_since_meal;

	pthread_mutex_lock(&table->meal_lock);
	time_since_meal = get_time() - table->philos[i].last_meal_time;
	pthread_mutex_unlock(&table->meal_lock);
	if (should_die(table, time_since_meal))
	{
		pthread_mutex_lock(&table->print_lock);
		pthread_mutex_lock(&table->death_lock);
		if (!table->someone_died && !table->all_ate)
		{
			table->someone_died = 1;
			printf("%lld %d %s\n",
				get_time() - table->start_time,
				table->philos[i].id, DEAD);
		}
		pthread_mutex_unlock(&table->death_lock);
		pthread_mutex_unlock(&table->print_lock);
		return (1);
	}
	return (0);
}

static int	check_all_ate(t_table *table)
{
	int	i;
	int	full_count;

	if (table->must_eat == -1)
		return (0);
	full_count = 0;
	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->meal_lock);
		if (table->philos[i].meals_eaten >= table->must_eat)
			full_count++;
		pthread_mutex_unlock(&table->meal_lock);
		i++;
	}
	if (full_count == table->num_philos)
	{
		pthread_mutex_lock(&table->death_lock);
		table->all_ate = 1;
		pthread_mutex_unlock(&table->death_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		while (i < table->num_philos)
		{
			if (check_death(table, i))
				return (NULL);
			i++;
		}
		if (check_all_ate(table))
			return (NULL);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:04:53 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/14 18:22:11 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	destroy_forks(pthread_mutex_t *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->print_lock, NULL))
		return (0);
	if (pthread_mutex_init(&table->death_lock, NULL))
		return (pthread_mutex_destroy(&table->print_lock), 0);
	if (pthread_mutex_init(&table->meal_lock, NULL))
	{
		pthread_mutex_destroy(&table->print_lock);
		pthread_mutex_destroy(&table->death_lock);
		return (0);
	}
	return (1);
}

int	clean_init_fail(t_table *table)
{
	if (table->philos)
		free(table->philos);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->death_lock);
	pthread_mutex_destroy(&table->meal_lock);
	return (0);
}

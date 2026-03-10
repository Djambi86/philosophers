/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:05:34 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/07 12:00:00 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static void	what_args_needed(void)
{
	printf("Usage: ./philo number_of_philosophers time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}

static int	start_simulation(t_table *table)
{
	int			i;
	pthread_t	monitor;

	table->start_time = get_time();
	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].last_meal_time = table->start_time;
		if (pthread_create(&table->philos[i].thread, NULL,
				philo_routine, &table->philos[i]))
			return (0);
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, table))
		return (0);
	if (pthread_join(monitor, NULL))
		return (0);
	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		what_args_needed();
		return (1);
	}
	if (!init_table(&table, argc, argv))
		return (1);
	if (!start_simulation(&table))
	{
		cleanup(&table);
		return (1);
	}
	cleanup(&table);
	return (0);
}

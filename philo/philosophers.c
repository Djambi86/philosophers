/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:47:57 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/16 21:48:03 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static void	what_args_needed(void)
{
	printf("Usage: ./philo number_of_philosophers time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}

static void	set_stop(t_table *table)
{
	pthread_mutex_lock(&table->death_lock);
	table->someone_died = 1;
	pthread_mutex_unlock(&table->death_lock);
}

static void	join_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
		pthread_join(table->philos[i++].thread, NULL);
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
		{
			set_stop(table);
			while (--i >= 0)
				pthread_join(table->philos[i].thread, NULL);
			return (0);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, table))
		return (set_stop(table), join_all(table), 0);
	pthread_join(monitor, NULL);
	join_all(table);
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

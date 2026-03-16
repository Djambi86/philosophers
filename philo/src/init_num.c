/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:18:16 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/16 00:00:00 by oai               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long	ft_atol(char *s)
{
	int			i;
	long long	result;
	int			digit;

	result = 0;
	i = 0;
	while (ft_is_space(s[i]))
		i++;
	if (!ft_is_sign(s, &i))
		return (-2);
	if (!no_letters(s[i]))
		return (-2);
	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - '0';
		if (result > (LLONG_MAX - digit) / 10)
		{
			printf("Number too large!\n");
			return (-2);
		}
		result = result * 10 + digit;
		i++;
	}
	while (ft_is_space(s[i]))
		i++;
	if (s[i] != '\0')
	{
		printf("No letters allowed!\n");
		return (-2);
	}
	return (result);
}

int	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		return (0);
	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			destroy_forks(table->forks, i);
			free(table->forks);
			table->forks = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_philos(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!table->philos)
		return (0);
	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal_time = table->start_time;
		table->philos[i].table = table;
		i++;
	}
	return (1);
}

int	init_table_part2_dilogy(t_table *table, char **argv)
{
	table->num_philos = ft_atol(argv[1]);
	if (table->num_philos == -2)
		return (0);
	table->time_to_die = ft_atol(argv[2]);
	if (table->time_to_die == -2)
		return (0);
	table->time_to_eat = ft_atol(argv[3]);
	if (table->time_to_eat == -2)
		return (0);
	table->time_to_sleep = ft_atol(argv[4]);
	if (table->time_to_sleep == -2)
		return (0);
	table->must_eat = -1;
	table->someone_died = 0;
	table->all_ate = 0;
	return (1);
}

int	init_table(t_table *table, int argc, char **argv)
{
	table->philos = NULL;
	table->forks = NULL;
	table->start_time = 0;
	if (!init_table_part2_dilogy(table, argv))
		return (0);
	if (argc == 6)
		table->must_eat = ft_atol(argv[5]);
	if (table->must_eat == -2)
		return (0);
	else if (table->must_eat == 0)
		return (0);
	if (!min_num_args(table) || !init_mutexes(table))
		return (0);
	if (!init_philos(table))
		return (clean_init_fail(table));
	if (!init_forks(table))
		return (clean_init_fail(table));
	return (1);
}

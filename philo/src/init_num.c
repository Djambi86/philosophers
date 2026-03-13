/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:18:16 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/13 21:01:27 by dabdulka         ###   ########.fr       */
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
		return (-1);
	if (!no_letters(s[i]))
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - '0';
		if (result > (LLONG_MAX - digit) / 10)
		{
			printf("Number too large!\n");
			return (-1);
		}
		result = result * 10 + digit;
		i++;
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
			return (0);
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
		table->philos[i].last_meal_time = 0;
		table->philos[i].table = table;
		i++;
	}
	return (1);
}

int	init_table_part2_dilogy(t_table *table, char **argv)
{
	table->num_philos = (int)ft_atol(argv[1]);
	if (table->num_philos == -1)
		return (0);
	table->time_to_die = ft_atol(argv[2]);
	if (table->time_to_die == -1)
		return (0);
	table->time_to_eat = ft_atol(argv[3]);
	if (table->time_to_eat == -1)
		return (0);
	table->time_to_sleep = ft_atol(argv[4]);
	if (table->time_to_sleep == -1)
		return (0);
	table->must_eat = -1;
	table->someone_died = 0;
	table->all_ate = 0;
	return (1);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (!init_table_part2_dilogy(table, argv))
		return (0);
	if (argc == 6)
		table->must_eat = (int)ft_atol(argv[5]);
	if (!min_num_args(table))
		return (0);
	if (pthread_mutex_init(&table->print_lock, NULL))
		return (0);
	if (pthread_mutex_init(&table->death_lock, NULL))
		return (0);
	if (pthread_mutex_init(&table->meal_lock, NULL))
		return (0);
	if (!init_philos(table))
		return (0);
	if (!init_forks(table))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 12:00:00 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/07 12:00:00 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long ms)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(100);
}

void	print_status(t_philo *philo, char *status)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->table->death_lock);
	if (philo->table->someone_died || philo->table->all_ate)
	{
		pthread_mutex_unlock(&philo->table->death_lock);
		return ;
	}
	timestamp = get_time() - philo->table->start_time;
	pthread_mutex_unlock(&philo->table->death_lock);
	pthread_mutex_lock(&philo->table->print_lock);
	printf("%lld %d %s\n", timestamp, philo->id, status);
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	cleanup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->death_lock);
	pthread_mutex_destroy(&table->meal_lock);
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:37:01 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/14 16:04:02 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	take_forks(t_philo *philo, int left, int right)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[right]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->table->forks[left]);
		print_status(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[left]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->table->forks[right]);
		print_status(philo, FORK);
	}
}

int	philo_eat(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->table->num_philos;
	if (philo->table->num_philos == 1)
	{
		pthread_mutex_lock(&philo->table->forks[left]);
		print_status(philo, FORK);
		ft_usleep(philo->table->time_to_die + 1);
		pthread_mutex_unlock(&philo->table->forks[left]);
		return (0);
	}
	take_forks(philo, left, right);
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[left]);
	pthread_mutex_unlock(&philo->table->forks[right]);
	return (1);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, SLEEP);
	ft_usleep(philo->table->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, THINK);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 2);
	while (!is_dead_or_full(philo))
	{
		if (!philo_eat(philo))
			break ;
		if (is_dead_or_full(philo))
			break ;
		philo_sleep(philo);
		if (is_dead_or_full(philo))
			break ;
		philo_think(philo);
	}
	return (NULL);
}

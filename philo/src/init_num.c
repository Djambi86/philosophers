/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:18:16 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/01 18:18:16 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// create a function where philos call the fork function through thread and also mutex it, so that 1 fork is left untouched
int ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return 1;
	return 0;
}

static int ft_is_negapositiv(char *s, int *i)
{
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
		{
			printf("Only positive numbers please, hoyoooooo!\n");
			return (0);
		}
		(*i)++;
	}
	if (s[*i] == '-' || s[*i] == '+')
	{
			printf("Too many signs big boy, hoyoooooo!\n");
			return (0);
	}
	return (1);
}

long long ft_atol(char *s)
{
	int i;
	long long result;
	int zero;
	int digit;

	result = 0;
	i = 0;
	while (ft_is_space(s[i]))
		i++;
	if (!(zero = ft_is_negapositiv(s, &i)))
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - '0';
		if (result > (LLONG_MAX - digit) / 10)
		{
			printf("Too big NUMBER big boy, hoyoooooo!\n");
			return (0);
		}
		result = result * 10 + digit;
		//result += s[i] - '0';
		i++;
	}
	return (result);
}

int init_philos(t_philo *philo, t_table *table, char **str_arr)
{
	if (!(philo->number_of_philosophers = ft_atol(str_arr[1])))
		return (0);
	if (!(table->fork_idx = ft_atol(str_arr[1])))
		return (0);
	if (!(philo->time_to_die = ft_atol(str_arr[2])))
		return (0);
	if (!(philo->time_to_eat = ft_atol(str_arr[3])))
		return (0);
	if (!(philo->time_to_sleep = ft_atol(str_arr[4])))
		return (0);
	/*philo->number_of_philosophers = 12323;
	table->fork_idx = 0; 
	char *s = str_arr[1];
	printf("error nervt%s\n", s);*/
	return (1);
}

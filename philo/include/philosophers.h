/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:05:44 by dabdulka          #+#    #+#             */
/*   Updated: 2026/03/17 21:16:58 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>
# include <limits.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DEAD "died"

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	long long		num_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		must_eat;
	int				someone_died;
	int				all_ate;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
}	t_table;

/*trash, hater, NormIsMyBiggestOP, ItShouldParish*/
int			is_dead_or_full(t_philo *philo);
int			no_letters(char c);
int			ft_is_sign(char *s, int *i);
int			ft_is_space(char c);
int			min_num_args(t_table *table);

/*init_num_part2... cannot believe I had to make a part2,
							 ALL BECAUSE OF NORMINETTE*/
void		destroy_forks(pthread_mutex_t *forks, int count);
int			init_mutexes(t_table *table);
int			clean_init_fail(t_table *table);

/* init */
int			init_table_part2_dilogy(t_table *table, char **argv);
int			init_table(t_table *table, int argc, char **argv);
int			init_philos(t_table *table);
int			init_forks(t_table *table);
long long	ft_atol(char *s);

/* utils */
long long	get_time(void);
void		ft_usleep(long long ms, t_philo *philo);
void		print_status(t_philo *philo, char *status);
void		cleanup(t_table *table);
int			check_overflow(long long result, char c);

/* loop */
void		*philo_routine(void *arg);
int			philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

/* monitor */
void		*monitor_routine(void *arg);

#endif

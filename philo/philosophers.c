/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:05:34 by dabdulka          #+#    #+#             */
/*   Updated: 2026/02/26 13:05:34 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void what_args_needed(void)
{
	printf("Incorrect number of arguments, please give me:\n");
	printf("number_of_philosophers\ntime_to_die\ntime_to_eat\n");
	printf("time_to_sleep\n");
	printf("and optionally - >[number_of_times_each_philosopher_must_eat]\n");
}

int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		what_args_needed();
		return (1);
	}
	return 120;
}
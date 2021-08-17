/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:45:18 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/17 14:44:01 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!is_digit(av[i][j]))
				write(2, "non numeric parameters\n", 23);
			if (!is_digit(av[i][j]))
				return (1);
		}
		if (ft_atoi(av[i]) > INT_MAX)
			write (2, "one of the value is too big\n", 28);
		if (ft_atoi(av[i]) > INT_MAX)
			return (1);
	}
	if (ft_atoi(av[1]) <= 1 || ft_atoi(av[1]) == -1 || ft_atoi(av[1]) > 200)
		write(2, "wrong number of philosophers\n", 29);
	if (ft_atoi(av[1]) <= 1 || ft_atoi(av[1]) > 200)
		return (1);
	return (0);
}

int	init_struct(t_global *global, char **av)
{
	int	i;

	i = -1;
	if (check_args(av))
		return (1);
	global->number_of_philos = ft_atoi(av[1]);
	global->time_to_die = ft_atoi(av[2]);
	global->time_to_eat = ft_atoi(av[3]);
	global->time_to_sleep = ft_atoi(av[4]);
	global->dead_philos = 0;
	global->philo_satiated = 0;
	global->end_meal = 0;
	global->number_of_meals = 0;
	if (av[5])
		global->number_of_meals = ft_atoi(av[5]);
	init_philo(global);
	pthread_mutex_init(&global->writing, NULL);
	while (++i < global->number_of_philos)
		pthread_mutex_init(&global->forks[i], NULL);
	return (0);
}

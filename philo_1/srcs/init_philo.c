/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:44:40 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/17 14:19:15 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_global *global)
{
	int	i;

	i = -1;
	while (++i < global->number_of_philos)
	{
		global->philo[i].id = i + 1 ;
		global->philo[i].global = global;
		global->philo[i].last_meal = timestamp();
		global->philo[i].left_fork_id = i + 1 ;
		global->philo[i].right_fork_id = (i + 2) % global->number_of_philos;
		global->philo[i].number_of_meals = 0;
	}
	return (0);
}

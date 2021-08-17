/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:57:49 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/16 20:13:15 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	death_monitoring(t_philo *philo)
{
	long long	time;

	time = timestamp();
	if (time - philo->last_meal > (philo->global->time_to_die))
	{
		display_message(philo, " died\n");
		philo->global->dead_philos++;
		return (1);
	}
	if (philo->global->number_of_meals)
	{
		if (philo->global->number_of_philos == philo->global->philo_satiated)
		{
			philo->global->end_meal++;
			display_message(0, "all philos are satiated\n");
			return (1);
		}
	}
	return (0);
}

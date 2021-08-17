/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launchthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:07:19 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/16 17:14:55 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	launchthread(t_global *global)
{
	int			i;
	t_philo		*philo;
	pthread_t	thread;

	i = 0;
	global->start = timestamp();
	while (i < global->number_of_philos)
	{
		philo = &global->philo[i];
		pthread_create(&thread, NULL, &routine, (void *)philo);
		pthread_detach(thread);
		i += 2;
	}
	i = 1;
	while (i < global->number_of_philos)
	{
		philo = &global->philo[i];
		pthread_create(&thread, NULL, &routine, (void *)philo);
		pthread_detach(thread);
		i += 2;
	}
	while (!death_monitoring(philo))
		;
}

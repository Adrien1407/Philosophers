/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:45:59 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/17 14:46:16 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	display_message(t_philo *philo, char *message)
{
	if (philo == 0)
		write(1, message, ft_strlen(message));
	else if (!(philo->global->dead_philos) && (!(philo->global->end_meal)))
	{
		pthread_mutex_lock(&philo->global->writing);
		if (!(philo->global->dead_philos) && (!(philo->global->end_meal)))
		{
			if ((timestamp() - philo->global->start < 10))
				write(1, "00", 2);
			ft_putnbr(timestamp() - philo->global->start);
			write(1, " ", 1);
			ft_putnbr((philo->id));
			write(1, message, ft_strlen(message));
		}
		pthread_mutex_unlock(&philo->global->writing);
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->forks[philo->right_fork_id]);
	display_message(philo, " has taken fork\n");
	pthread_mutex_lock(&philo->global->forks[philo->left_fork_id]);
	display_message(philo, " has taken fork\n");
	display_message(philo, " is eating\n");
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&philo->global->forks[philo->right_fork_id]);
	pthread_mutex_unlock(&philo->global->forks[philo->left_fork_id]);
	philo->number_of_meals++;
	ft_usleep((philo->global->time_to_eat));
	if (philo->number_of_meals == philo->global->number_of_meals)
		philo->global->philo_satiated++;
}

void	philo_sleep(t_philo *philo)
{
	display_message(philo, " is sleeping\n");
	ft_usleep(philo->global->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	display_message(philo, " is thinking\n");
}

void	*routine(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *) philo;
	while (1)
	{
		if (tmp->global->dead_philos == 0 && tmp->global->end_meal == 0)
			philo_eat(tmp);
		if (tmp->global->dead_philos == 0 && tmp->global->end_meal == 0)
			philo_sleep(tmp);
		if (tmp->global->dead_philos == 0 && tmp->global->end_meal == 0)
			philo_think(tmp);
	}
	return ((void *) 0);
}

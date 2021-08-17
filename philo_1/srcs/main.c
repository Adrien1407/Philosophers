/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:50:46 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/17 14:39:12 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_global	global;
	int			i;

	i = 0;
	if (!(ac == 5 || ac == 6))
	{
		write(2, "wrong number of arguments\n", 26);
		return (1);
	}
	if (init_struct(&global, av))
		return (1);
	launchthread(&global);
	usleep(10000);
	pthread_mutex_destroy(&global.writing);
	return (0);
}

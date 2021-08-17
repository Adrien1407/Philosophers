/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:32:24 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/17 14:33:11 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_usleep(int duration)
{
	long	start;
	long	current;

	start = timestamp();
	current = start;
	while (duration > current - start)
	{
		usleep(100);
		current = timestamp();
	}
}

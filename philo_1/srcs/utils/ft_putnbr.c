/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:51:17 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/12 17:13:33 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_putnbr(long long c)
{
	if (c == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (c < 0)
	{
		c = -c;
		write(1, "-", 1);
	}
	if (c > 9)
		ft_putnbr(c / 10);
	c = c % 10 + 48;
	write(1, &c, 1);
}

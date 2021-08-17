/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:11:17 by adlancel          #+#    #+#             */
/*   Updated: 2021/08/17 14:47:38 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	int				left_fork_id;
	int				right_fork_id;
	int				number_of_meals;
	struct s_global	*global;
}				t_philo;

typedef struct s_global
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_satiated;
	int				number_of_meals;
	int				dead_philos;
	int				end_meal;
	long long		start;
	t_philo			philo[250];
	pthread_mutex_t	writing;
	pthread_mutex_t	forks[250];
}				t_global;

long long	ft_atoi(char *str);
int			is_digit(int c);
int			ft_strlen(char *str);
void		ft_putnbr(long long c);
void		ft_usleep(int duration);
long long	timestamp(void);
int			init_struct(t_global *global, char **av);
void		*routine(void	*philo);
void		launchthread(t_global *global);
void		display_message(t_philo *philo, char *message);
int			init_struct(t_global *global, char **av);
int			death_monitoring(t_philo *philo);
int			init_philo(t_global *global);
int			exit_and_free(t_global *global);
//int			main(int ac, char **av);

#endif

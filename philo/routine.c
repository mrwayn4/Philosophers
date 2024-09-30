/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:10:21 by ibouram           #+#    #+#             */
/*   Updated: 2024/09/30 23:47:36 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_lock);
	printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	ft_eat(t_philo *philos)
{
	pthread_mutex_lock(philos->left_f);
	print_message(philos, "has taking a fork");
	pthread_mutex_lock(philos->right_f);
	print_message(philos, "has taking a fork");
	print_message(philos, "is eating");
	pthread_mutex_lock(&philos->data->eat_lock);
	philos->nb_meals++;
	pthread_mutex_unlock(&philos->data->eat_lock);
	pthread_mutex_lock(&philos->data->time_lock);
	philos->last_meal = get_time();
	pthread_mutex_unlock(&philos->data->time_lock);
	ft_usleep(philos->data->time_to_eat);
	pthread_mutex_unlock(philos->left_f);
	pthread_mutex_unlock(philos->right_f);
}

void	ft_sleep_think(t_philo *philos)
{
	print_message(philos, "is sleeping");
	ft_usleep(philos->data->time_to_sleep);
	print_message(philos, "is thinking");
}

void	*routine(t_philo *philos)
{
	if (philos->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (philos->data->nb_time_eat != -1
			&& philos->data->nb_time_eat == philos->nb_meals)
			return (NULL);
		ft_eat(philos);
		ft_sleep_think(philos);
	}
	return (NULL);
}

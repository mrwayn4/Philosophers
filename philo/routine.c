/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:10:21 by ibouram           #+#    #+#             */
/*   Updated: 2024/10/16 18:47:46 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (philo->data->d_flag)
	{
		pthread_mutex_unlock(&philo->data->print_lock);
		return ;
	}
	printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	ft_eat(t_philo *philos)
{
	pthread_mutex_lock(philos->left_f);
	print_message(philos, "has taking a fork");
	if (philos->data->nb_philo == 1)
	{
		pthread_mutex_unlock(philos->left_f);
		return ;
	}
	pthread_mutex_lock(philos->right_f);
	print_message(philos, "has taking a fork");
	print_message(philos, "is eating");
	pthread_mutex_lock(&philos->data->eat_lock);
	philos->nb_meals++;
	pthread_mutex_unlock(&philos->data->eat_lock);
	pthread_mutex_lock(&philos->data->time_lock);
	philos->last_meal = get_time();
	pthread_mutex_unlock(&philos->data->time_lock);
	ft_usleep(philos->data->time_to_eat, philos->data);
	pthread_mutex_unlock(philos->left_f);
	pthread_mutex_unlock(philos->right_f);
}

void	ft_sleep_think(t_philo *philos)
{
	print_message(philos, "is sleeping");
	ft_usleep(philos->data->time_to_sleep, philos->data);
	print_message(philos, "is thinking");
}

void	*routine(t_philo *philos)
{
	if (philos->id % 2 == 0)
		usleep(1000);
	while (1 && !philos->data->d_flag)
	{
		if (philos->data->nb_time_eat != -1
			&& philos->data->nb_time_eat == philos->nb_meals)
			return (NULL);
		ft_eat(philos);
		ft_sleep_think(philos);
	}
	return (NULL);
}

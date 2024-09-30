/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:39:42 by ibouram           #+#    #+#             */
/*   Updated: 2024/10/01 00:13:19 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy(t_init *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->eat_lock);
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	free(data->philos);
}

int	meals_checker(t_init *data, int i)
{
	pthread_mutex_lock(&data->eat_lock);
	if (data->nb_time_eat != -1 && data->philos[i].nb_meals == data->nb_time_eat
		&& data->philos[i].flg == 0)
	{
		data->all_eat++;
		data->philos[i].flg = 1;
	}
	if (data->all_eat == data->nb_philo)
	{
		pthread_mutex_unlock(&data->eat_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->eat_lock);
	return (0);
}

int	death_checker(t_init *data, int i)
{
	pthread_mutex_lock(&data->time_lock);
	if (get_time() - data->philos[i].last_meal >= (size_t)data->time_to_die)
	{
		print_message(data->philos, "died");
		pthread_mutex_unlock(&data->time_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->time_lock);
	pthread_mutex_unlock(&data->print_lock);
	return (0);
}

void	monitor(t_init *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (meals_checker(data, i) || death_checker(data, i))
				return ;
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:54:13 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/14 14:33:37 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(char **str, t_init *data)
{
	data->nb_philo = *str[1];
	data->time_to_die = *str[2];
	data->time_to_eat = *str[3];
	data->time_to_sleep = *str[4];
	if (str[5])
		data->nb_time_eat = *str[5];
	else
		data->nb_time_eat = -1;
}

void	init_forks(t_init *data)
{
	int	i;

	i = 0;
	data->forks = malloc (sizeof(pthread_mutex_t) * (data->nb_philo));
	if (!data->forks)
		return ;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_philos(t_init *data)
{
	int	i;
	int j;

	i = 0;
	data->philos = malloc (sizeof(pthread_mutex_t) * (data->nb_philo));
	if (!data->philos)
		return ;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].nb_meals = 0;
		data->philos[i].start_time = get_time();
		data->philos[i].last_meal = get_time();
		data->philos[i].left_f = &data->forks[i];
		data->philos[i].right_f = &data->forks[i + 1 % data->nb_philo];
		i++;
	}
	j = 0;
	while (j < data->nb_philo)
	{
		// pthread_mutex_init(&data->philos[i], NULL);
		// pthread_create(&data->philos[i].thread, NULL, routine, NULL);
		j++;
	}
}

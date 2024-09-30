/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:54:13 by ibouram           #+#    #+#             */
/*   Updated: 2024/09/30 23:41:53 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(char **str, t_init *data)
{
	data->nb_philo = ft_atoi(str[1]);
	data->time_to_die = ft_atoi(str[2]);
	data->time_to_eat = ft_atoi(str[3]);
	data->time_to_sleep = ft_atoi(str[4]);
	if (str[5])
		data->nb_time_eat = ft_atoi(str[5]);
	else
		data->nb_time_eat = -1;
}

void	init_forks(t_init *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->time_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);
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

	i = 0;
	data->philos = malloc (sizeof(t_philo) * (data->nb_philo));
	if (!data->philos)
		return ;
	data->start_time = get_time();
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].nb_meals = 0;
		data->philos[i].eating = 0;
		data->all_eat = 0;
		data->philos[i].last_meal = get_time();
		data->philos[i].flg = 0;
		data->philos[i].left_f = &data->forks[i];
		data->philos[i].data = data;
		if (i == 0)
			data->philos[i].right_f = &data->forks[data->nb_philo - 1];
		else
			data->philos[i].right_f = &data->forks[i - 1];
		i++;
	}
}

void	init_data(char **str, t_init *data)
{
	init_arg(str, data);
	init_forks(data);
	init_philos(data);
}

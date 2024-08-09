/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:54:13 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/09 11:40:14 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(char **str, t_philo *philo)
{
	philo->nb_philo = *str[1];
	philo->time_to_die = *str[2];
	philo->time_to_eat = *str[3];
	philo->time_to_sleep = *str[4];
	if (str[5])
		philo->nb_philo = *str[5];
	// else
	// 	philo->nb_philo = -1;
}

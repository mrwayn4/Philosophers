/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:19:03 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/14 14:27:08 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	time;
	size_t	time_s;
	size_t	time_mcs;

	gettimeofday(&time, NULL);
	time_s = time.tv_sec * 1000;
	time_mcs = time.tv_usec / 1000;
	return (time_s + time_mcs);
}

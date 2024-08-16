/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:47:29 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/16 18:10:05 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pars_arg(char *str)
{
	if (!valid_arg(str) || ft_atoi(str) == -1 || ft_atoi(str) == 0)
	{
		ft_putstr_fd("Eroor: Invalid Input\n", 2);
		return (1);
	}
	return (0);
}

int	check_input(char **s)
{
	if (pars_arg(s[1]) || pars_arg(s[2]) || pars_arg(s[3]) || pars_arg(s[4]))
		return (1);
	if (s[5] && pars_arg(s[5]))
		return (1);
	return (0);
}

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

int	main(int ac, char **av)
{
	t_init	philo;
	int		i;
	int		j;

	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (1);
	}
	if (check_input(av) == 1)
		return (1);
	init_data(av, &philo);
	(1) && (i = -1 , j = -1);
	while (++i < philo.nb_philo)
		pthread_create(&philo.philos[i].thread, NULL, &routine, &philo.philos[i]);
	while (++j < philo.nb_philo)
		pthread_detach(philo.philos[j].thread);
	// monitor(&philo);
	// destroy(&philo);
	return (0);
}

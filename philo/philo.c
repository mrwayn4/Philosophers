/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:47:29 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/13 10:07:18 by ibouram          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_init	philo;

	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (1);
	}
	if (check_input(av) == 1)
		return (1);
	init_arg(av, &philo);
	init_forks(&philo);
	init_philos(&philo);
	return (0);
}

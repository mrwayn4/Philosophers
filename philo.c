/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:47:29 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/08 19:39:13 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pars_arg(char *str)
{
	ft_atoi(str);
	if (!valid_arg(str))
	{
		ft_putstr_fd("Eroor: Invalid Input\n", 2);
		return (1);
	}
	return (0);
}

int main (int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (1);
	}
	pars_arg(av[1]);
	pars_arg(av[2]);
	pars_arg(av[3]);
	pars_arg(av[4]);
	if (ac == 6)
		pars_arg(av[5]);
	return (0);
}

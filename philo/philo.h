/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:47:33 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/09 11:36:57 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_eat;
}					t_philo;

void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);
int		valid_arg(char *s);
int		ft_atoi(const char *str);
void	init_arg(char **str, t_philo *philo);

#endif

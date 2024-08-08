/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:47:33 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/08 19:23:57 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);
int		valid_arg(char *s);
int		ft_atoi(const char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:47:33 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/16 17:14:29 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	size_t			last_meal;
	int				nb_meals;
	int				start_time;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	*left_f;
}					t_philo;


typedef struct s_init
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_eat;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_init;

void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);
int		valid_arg(char *s);
int		ft_atoi(const char *str);
void	init_arg(char **str, t_init *philo);
size_t	get_time(void);
void	init_philos(t_init *data);
void	init_forks(t_init *data);
void init_data(char **str, t_init *data);
void	*routine(void *philo);

#endif

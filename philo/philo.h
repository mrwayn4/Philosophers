/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:47:33 by ibouram           #+#    #+#             */
/*   Updated: 2024/10/16 18:48:44 by ibouram          ###   ########.fr       */
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
	pthread_mutex_t	*right_f;
	pthread_mutex_t	*left_f;
	int				flg;
	struct s_init	*data;
}					t_philo;

typedef struct s_init
{
	_Atomic int		d_flag;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_eat;
	int				all_eat;
	size_t			start_time;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	time_lock;
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
void	init_data(char **str, t_init *data);
void	*routine(t_philo *philos);
size_t	ft_usleep(size_t time, t_init *data);
void	destroy(t_init *data);
void	monitor(t_init *data);
void	print_message(t_philo *philo, char *msg);

#endif

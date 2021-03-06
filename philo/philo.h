/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:08:54 by tkang             #+#    #+#             */
/*   Updated: 2022/07/18 14:08:56 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_args
{
	int				philo_cnt;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	int				eat_time;
	unsigned long	die_time;
	int				sleep_time;
	int				eat_cnt;
	int				finish;
	int				finished_eat_cnt;
}	t_args;

typedef struct s_philo
{
	t_args			*args;
	pthread_t		p_thread;
	unsigned long	start_time;
	int				id;
	int				left;
	int				right;
	unsigned long	eat_time;
	int				eat_cnt;
}	t_philo;

void			init_philo(t_philo **philo, t_args *args);
void			init_args(t_args *args, int ac, char *av[]);

unsigned long	get_time(void);
void			exit_trap(int sig);
int				my_atoi(const char *str);

void			*routine(void *data);

void			eat(t_philo *philo);
void			sleeping(t_philo *philo);
void			think(t_philo *philo);

void			time_spend(unsigned long wait_time, t_args *args);

void			printer(t_philo *philo, int id, char *msg);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:16:07 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/25 16:16:09 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_args
{
	pid_t		*philosophers;
	pid_t		monitor_min_dining;
	sem_t		*forks_all;
	sem_t		*lt_eating;
	sem_t		*printing;
	sem_t		*number_of_diners;
	pthread_t	monitoring;
	size_t		number_philo;
	size_t		id_philosopher;
	long long	time_die;
	long long	time_eat;
	long long	time_sleep;
	size_t		min_each_eat;
	size_t		number_dining;
	long long	start_time;
	long long	time_last_diner;

}	t_args;

/* CHECK_ARGS */
int		ft_check(int argc, char **argv);
int		ft_print_error(char *str);
/* LIB FUNCS */
int		ft_atoi(const char *str);
/* FT_READ_ARGS */
void	ft_read_args(char **argv, t_args *args);
/* FT_INIT_DATA */
int		ft_init_data(t_args *args);
/* simulation */
int		ft_start_simulation(t_args *args);
int		ft_philo_simulation(t_args *args);
int		ft_print_data(char *text, t_args *alldata);
void	ft_thinking(t_args *args);
void	ft_sleeping(t_args *args);
void	ft_eating(t_args *args);
int		ft_finish_dinner(t_args *args);

/* TIME AND SLEEP FUNCS */
void	ft_smart_sleep(long long interval);
void	ft_current_time(long long *current);

/*monitoring*/
void	ft_check_number_dining(t_args *args);
void	*ft_monitoring(void *args);
void	ft_exit(t_args *args);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:19:46 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/25 16:22:53 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void	ft_one_philosopher(t_args *args)
{
	ft_thinking(args);
	sem_wait(args->forks_all);
	sem_wait(args->printing);
	ft_print_data("%lld %zu has taken a fork\n", args);
	sem_post(args->printing);
	ft_smart_sleep(args->time_die);
	ft_print_data("%lld %zu died\n", args);
	sem_post(args->forks_all);
	exit (0);
}

void	ft_eating(t_args *args)
{
	long long	timestamp;

	sem_wait(args->forks_all);
	sem_wait(args->printing);
	ft_print_data("%lld %zu has taken a fork\n", args);
	sem_post(args->printing);
	sem_wait(args->forks_all);
	sem_wait(args->printing);
	ft_print_data("%lld %zu has taken a fork\n", args);
	sem_post(args->printing);
	sem_wait(args->printing);
	ft_print_data("%lld %zu is eating\n", args);
	sem_post(args->printing);
	sem_wait(args->lt_eating);
	ft_current_time(&timestamp);
	args->time_last_diner = timestamp;
	sem_post(args->lt_eating);
	args->min_each_eat++;
	if (args->number_dining > 0)
	{
		if (args->min_each_eat == args->number_dining)
			sem_post(args->number_of_diners);
	}
	ft_smart_sleep(args->time_eat);
}

void	ft_sleeping(t_args *args)
{
	sem_wait(args->printing);
	ft_print_data("%lld %zu is sleeping\n", args);
	sem_post(args->printing);
	ft_smart_sleep(args->time_sleep);
}

void	ft_thinking(t_args *args)
{
	sem_wait(args->printing);
	ft_print_data("%lld %zu is thinking\n", args);
	sem_post(args->printing);
}

int	ft_philo_simulation(t_args *args)
{
	if (pthread_create(&(args->monitoring), NULL, ft_monitoring, (void *)args))
	{
		printf("Error in thread in Philo N %zu", args->id_philosopher);
		return (1);
	}
	if (args->number_philo == 1)
		ft_one_philosopher(args);
	ft_thinking(args);
	if (args->id_philosopher % 2 == 0)
		ft_smart_sleep(args->time_eat);
	while (1)
	{
		ft_eating(args);
		sem_post(args->forks_all);
		sem_post(args->forks_all);
		ft_sleeping(args);
		ft_thinking(args);
	}
	pthread_join(args->monitoring, NULL);
	exit(0);
	return (0);
}

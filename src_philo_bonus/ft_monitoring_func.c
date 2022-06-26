/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:11:11 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/25 16:18:24 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_check_number_dining(t_args *args)
{
	size_t	i;

	i = 0;
	while (i < args->number_philo)
	{
		sem_wait(args->number_of_diners);
		i++;
	}
	exit(0);
}

void	*ft_monitoring(void *args)
{
	t_args		*alldata;
	long long	timestamp;

	alldata = (t_args *)args;
	while (1)
	{
		ft_current_time(&timestamp);
		sem_wait(alldata->lt_eating);
		if (timestamp - alldata->time_last_diner > alldata->time_die)
		{
			sem_post(alldata->lt_eating);
			sem_wait(alldata->printing);
			ft_print_data("%lld %zu died\n", alldata);
			sem_post(alldata->printing);
			break ;
		}
		sem_post(alldata->lt_eating);
		usleep(100);
	}
	exit(0);
	return (NULL);
}

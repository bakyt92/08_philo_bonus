/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:15:00 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/25 16:15:01 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_read_args(char **argv, t_args *args)
{
	args->number_philo = (size_t)ft_atoi(argv[1]);
	args->time_die = (size_t)ft_atoi(argv[2]);
	args->time_eat = (size_t)ft_atoi(argv[3]);
	args->time_sleep = (size_t)ft_atoi(argv[4]);
	if (argv[5])
		args->min_each_eat = (size_t)ft_atoi(argv[5]);
	else
		args->min_each_eat = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:11:37 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/25 16:17:05 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_exit(t_args *args)
{
	if (sem_close(args->lt_eating) == 0)
		sem_unlink("lt_eating");
	if (sem_close(args->printing) == 0)
		sem_unlink("printing");
	if (sem_close(args->number_of_diners) == 0)
		sem_unlink("number_of_diners");
	if (sem_close(args->forks_all) == 0)
		sem_unlink("forks_all");
	if (args->philosophers)
		free(args->philosophers);
	if (args)
		free(args);
}

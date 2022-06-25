/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:11:30 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/06/25 16:16:59 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_print_error(char *str)
{
	printf("\033[0;31m");
	printf("%s", str);
	printf("\033[0m");
	return (0);
}

static int	ft_isdigit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ' || str[i] == '+' || \
		(str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
			return (1);
		if (ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

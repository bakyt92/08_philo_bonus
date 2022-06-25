#include "philo_bonus.h"

int	ft_finish_dinner(t_args *args)
{
	int i;

	i = 0;
	ft_exit(args);
	while (i < args->number_philo)
	{
		kill(args->philosophers[i], SIGINT);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (ft_check(argc, argv))
	{
		ft_print_error("Wrong arguments\n");
		return (1);
	}
	args = malloc(sizeof(t_args));
	if (!args)
		return (1);
	ft_read_args(argv, args);
	if (ft_init_data(args))
	{
		ft_exit(args);
		return (1);
	}
	if (ft_start_simulation(args))
	{
		ft_exit(args);
		return (1);
	}
	ft_finish_dinner(args);
	return (0);
}

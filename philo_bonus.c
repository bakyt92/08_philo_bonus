#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_args		*args;

	if (ft_check(argc, argv))
	{
		ft_print_error("Wrong arguments\n");
		return (1);
	}
	args = malloc(sizeof(t_args));
	if (!args)
		return (1);
	ft_read_args(argv, args);

}

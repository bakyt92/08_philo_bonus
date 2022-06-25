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


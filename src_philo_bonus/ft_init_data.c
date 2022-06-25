#include "../philo_bonus.h"

int	ft_init_data(t_args *args)
{
	sem_unlink("forks_all");
	sem_unlink("lt_eating");
	sem_unlink("printing");
	sem_unlink("number_of_diners");
	args->forks_all = sem_open("forks_all", O_CREAT, 0664, args->number_philo);
	args->printing = sem_open("printing", O_CREAT, 0664, 1);
	args->lt_eating = sem_open("lt_eating", O_CREAT, 0664, 1);
	args->number_of_diners = sem_open("number_of_diners", O_CREAT, 0664, 0);
	args->philosophers = malloc(sizeof (pid_t *) * args->number_philo);
	if (!args->philosophers)
		return (1);
	if (args->forks_all == SEM_FAILED || args->printing == SEM_FAILED
			|| args->lt_eating == SEM_FAILED || args->number_of_diners == SEM_FAILED)
		return (1);
	else
		return (0);
}

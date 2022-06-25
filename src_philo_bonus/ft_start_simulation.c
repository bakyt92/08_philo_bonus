#include "../philo_bonus.h"

int	ft_print_data(char *text, t_args *alldata)
{
	long long	time_now;

	ft_current_time(&time_now);
	time_now = time_now - alldata->start_time;
	printf(text, time_now, alldata->id_philosopher);
	return (0);
}

int	ft_start_simulation(t_args *args)
{
	int	id;

	id = 0;
	ft_current_time(&(args->start_time));
	args->time_last_diner = args->start_time;
	args->monitor_min_dining = fork();
	if (args->monitor_min_dining == -1)
		return (1);
	if (args->monitor_min_dining == 0)
		ft_check_number_dining(args);
	while (id < args->number_philo)
	{
		args->philosophers[id] = fork();
		args->id_philosopher = id + 1;
		if (args->philosophers[id] == 0)
			ft_philo_simulation(args);
		if (args->philosophers[id] == -1)
			return (1);
	}
	waitpid(-1, NULL, 0);
	return (0);
}


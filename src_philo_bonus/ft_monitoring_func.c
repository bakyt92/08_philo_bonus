#include "../philo_bonus.h"

void	ft_check_number_dining(t_args *args)
{
	int i;

	i = 0;
	while (i < args->number_philo)
	{
		sem_wait(args->number_of_diners);
		i++;
	}
	exit(0);
}

int	ft_monitoring(void *args)
{
	t_args		*alldata;
	long long	timestamp;

	alldata = (t_args *)args;
	while (1)
	{
		ft_current_time(&timestamp);
		sem_wait(alldata->lt_eating);
		if (timestamp - alldata->start_time > alldata->time_die)
		{
			sem_post(alldata->lt_eating);
			sem_wait(alldata->printing);
			ft_print_data("%lld %zu died\n", alldata);
			sem_post(alldata->printing);
			break;
		}
		sem_post(alldata->lt_eating);
	}
	exit(0);
}
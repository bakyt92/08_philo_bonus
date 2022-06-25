
#include "../philo_bonus.h"

void	ft_current_time(long long *current)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	*current = start.tv_sec % 1000000 * 1000 + start.tv_usec / 1000;
}

void	ft_smart_sleep(long long interval)
{
	long long	begin;
	long long	end;

	ft_current_time(&begin);
	ft_current_time(&end);
	while (interval > end - begin)
	{
		ft_current_time(&end);
		usleep(100);
	}
}

cmake_minimum_required(VERSION 3.21)
project(08_philo_bonus C)

set(CMAKE_C_STANDARD 99)

add_executable(08_philo_bonus philo_bonus.c philo_bonus.h src_philo_bonus/ft_check.c src_philo_bonus/ft_read_args.c src_philo_bonus/ft_init_data.c src_philo_bonus/ft_atoi.c src_philo_bonus/ft_start_simulation.c src_philo_bonus/ft_time.c src_philo_bonus/ft_simulation.c src_philo_bonus/ft_monitoring_func.c src_philo_bonus/ft_exit_func.c)

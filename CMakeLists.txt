cmake_minimum_required(VERSION 3.21)
project(08_philo_bonus C)

set(CMAKE_C_STANDARD 99)

add_executable(08_philo_bonus philo_bonus.c philo_bonus.h src_philo_bonus/ft_check.c src_philo_bonus/ft_print_error.c src_philo_bonus/ft_read_args.c)

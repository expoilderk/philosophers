
#include "philo.h"

int check(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    return (0);
}

void    error_msg()
{
    printf("Invalid Arguments!\n");
}

void    help_msg()
{
    printf("Usage Mode:\n");
    printf("./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}
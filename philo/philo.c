/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:11:26 by mreis-me          #+#    #+#             */
/*   Updated: 2022/11/01 15:08:06 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    (void)argv;

    if(argc < 2 || argc > 6)
        help_msg();
    
    //Args: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
    
    
    //check args
    //error
    //init_philo
    //create_threads
    //join_threads

    return (0);
}

void    init_philo(t_philo *philo)
{
    philo->id = 1;
    philo->time_of_last_meal = 2000;
}
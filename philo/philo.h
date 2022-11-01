/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:09:25 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/31 23:58:07 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int id;
    int time_of_last_meal;
    //caracteristicas importantes de cada filosofo
    
}	t_philo;

typedef struct s_table
{
	t_philo philo;
    int     time_to_eat;
    int     time_to_sleep;
    int     time_to_die;
    int     number_of_philosophers;
    //variaveis do tipo thread e que estão ligadas ao fluxo
	
}	t_table;

// Philo

// Threads

// Actions

// Help or Error

// Utils

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:09:25 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/11 21:59:25 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define DEFAULT_NUM_TIMES_EAT 3
#define NUM_PHILOSOPHERS 5

// Struct para armazenar os dados de cada filósofo
typedef struct s_philo
{
    long id;
    int times_eaten;
    int last_meal;
    pthread_t thread;
} t_philo;

// Struct para armazenar os dados da mesa
typedef struct s_table
{
    int num_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_times_eat;
    t_philo *philo;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    pthread_mutex_t death;
} t_table;

// Philo
// void init_philo(t_table *philo);

// Threads

// Actions
void *dinner_routine(void *arg);
/*
eat();
think();
sleep();
*/

// Time
// long get_time_now();
long get_time(struct timeval timestamp);

// Help or Error
// int check(t_table *philo);

// Utils

#endif
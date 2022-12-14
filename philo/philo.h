/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:09:25 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/13 21:27:42 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

// Struct para armazenar os dados de cada filósofo
typedef struct s_philo
{
    int id;
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
    pthread_mutex_t print; // não utilizada ainda
    pthread_mutex_t death; // não utilizada ainda
} t_table;

// Init & Finish
t_table init(int argc, char **argv);
void init_table(int argc, char **argv, t_table *table);
void init_philo(t_table *table);
void init_forks(t_table *table);
void finish(t_table table);

// Threads routines
void *dinner(void *arg);
void *waiter(void *arg);

// Actions
int take_fork();
int eat();
int put_fork();
int sleeping();
int think();

// Time
// long get_time_now();
long get_time(struct timeval timestamp);

// Help or Error
void error_msg();
void help_msg();

// Checks
int check(int argc, char **argv);

// Utils
int ft_atoi(const char *str);
long int ft_atoi_l(const char *str);
int ft_isdigit(int c);
int ft_issign(char c);
void *lock_print(void *arg);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:09:25 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/22 10:54:56 by mreis-me         ###   ########.fr       */
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
    int left_fork;
    int right_fork;
    struct s_rules *rules;
    pthread_t thread;
} t_philo;

// Struct para armazenar os dados da mesa
typedef struct s_rules
{
    int num_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_times_eat;
    int all_satisfied;
    int someone_died;
    long start_time;
    t_philo *philo;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    pthread_mutex_t death; // não utilizada ainda
} t_rules;

// Init & Finish
void init(char **argv, t_rules *rules);
void init_rules(char **argv, t_rules *rules);
void init_philo(t_rules *table);
void init_mutex(t_rules *table);
void finish(t_rules *table);

// Threads routines
void *test_thread(void *arg);
void *dinner(void *arg);
void *waiter(void *arg);

// Actions
int take_fork();
int eat();
int put_fork();
int sleeping();
int think();

// Time
long timestamp();
long time_diff(long start, long end);
long time_travelled(struct timeval timestamp);

// Help or Error
void error_msg();
void help_msg();

// Checks
int check(int argc, char **argv);

// Libft
int ft_atoi(const char *str);
long int ft_atoi_l(const char *str);
int ft_isdigit(int c);
int ft_issign(char c);

// Utils
void lock_print(t_rules *rules, int id, char *string);

#endif
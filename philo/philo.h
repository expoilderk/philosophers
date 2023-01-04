/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:09:25 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 07:50:41 by mreis-me         ###   ########.fr       */
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
    long last_meal;
    int left_fork;
    int right_fork;
    struct s_rules *rules;
    pthread_t thread_philo;
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
    int finish;
    long start_time;
    t_philo *philo;
    pthread_mutex_t *m_forks;
    pthread_mutex_t m_print;
    pthread_mutex_t m_check;
    pthread_mutex_t m_finish;
} t_rules;

// Init & Finish
void init(char **argv, t_rules *rules);
void init_rules(char **argv, t_rules *rules);
void init_threads(t_rules *rules);
void init_mutex(t_rules *rules);
void finish(t_rules *rules);

// Threads routines
void *dinner(void *arg);
void *waiter(void *arg);

// Actions
void take_fork(t_rules *rules, t_philo *philo);
void eat(t_rules *rules, t_philo *philo);
void sleeping_and_thinking(t_rules *rules, t_philo *philo);

// Time
long timestamp();
long time_diff(long start, long end);
void smart_sleep(int ms);

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
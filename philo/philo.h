/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:09:25 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/05 15:14:08 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define INT_MAX 2147483647

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	long			last_meal;
	int				left_fork;
	int				right_fork;
	struct s_rules	*rules;
	pthread_t		thread_philo;
}	t_philo;

typedef struct s_rules
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_eat;
	int				all_satisfied;
	int				finish;
	long			start_time;
	t_philo			*philo;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_check;
	pthread_mutex_t	m_finish;
}	t_rules;

// Init & Finish
void	init(char **argv, t_rules *rules);
void	init_rules(char **argv, t_rules *rules);
void	init_threads(t_rules *rules);
void	init_mutex(t_rules *rules);
void	finish(t_rules *rules);

// Threads routines
void	*dinner(void *arg);
void	*monitor(void *arg);
int		check_finish(t_rules *rules);
void	waiter(t_rules *rules);

// Actions
void	eat(t_rules *rules, t_philo *philo);
int		get_fork_id(t_philo *philo, char type);
void	acquire_forks(t_rules *rules, int left_fork, int right_fork);
void	release_forks(t_rules *rules, int left_fork, int right_fork);
void	sleeping_and_thinking(t_rules *rules, t_philo *philo);

// Time
long	timestamp(void);
long	time_diff(long start, long end);
void	smart_sleep(int ms);

// Checks
int		check(char **argv, int i, int j);
void	error_msg(void);
void	help_msg(void);

// Utils
void	lock_print(t_rules *rules, int id, char *string);
long	ft_atoi_l(const char *str);
int		ft_isdigit(int c);
int		ft_issign(char c);

#endif

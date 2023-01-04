/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:08 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 11:21:54 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(char **argv, t_rules *rules)
{
	rules->start_time = timestamp();
	init_rules(argv, rules);
	init_mutex(rules);
	init_threads(rules);
}

void	init_rules(char **argv, t_rules *rules)
{
	rules->num_philosophers = (int)ft_atoi_l(argv[1]);
	rules->time_to_die = (int)ft_atoi_l(argv[2]);
	rules->time_to_eat = (int)ft_atoi_l(argv[3]);
	rules->time_to_sleep = (int)ft_atoi_l(argv[4]);
	rules->finish = 0;
	rules->all_satisfied = 0;
	rules->someone_died = 0;
	if (argv[5])
		rules->num_times_eat = (int)ft_atoi_l(argv[5]);
	else
		rules->num_times_eat = -1;
}

void	init_threads(t_rules *rules)
{
	int			i;
	pthread_t	thread_waiter;

	i = 0;
	rules->philo = malloc(sizeof(t_philo) * rules->num_philosophers);
	while (i < rules->num_philosophers)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].left_fork = i;
		rules->philo[i].right_fork = (i + 1) % rules->num_philosophers;
		rules->philo[i].times_eaten = 0;
		rules->philo[i].rules = rules;
		pthread_create(&rules->philo[i].thread_philo, NULL, dinner, \
				&rules->philo[i]);
		rules->philo[i].last_meal = timestamp();
		pthread_create(&thread_waiter, NULL, monitor, rules);
		pthread_detach(thread_waiter);
		i++;
	}
}

void	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	rules->m_forks = malloc(sizeof(pthread_mutex_t) * rules->num_philosophers);
	while (i < rules->num_philosophers)
		pthread_mutex_init(&rules->m_forks[i++], NULL);
	pthread_mutex_init(&rules->m_print, NULL);
	pthread_mutex_init(&rules->m_check, NULL);
	pthread_mutex_init(&rules->m_finish, NULL);
}

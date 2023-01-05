/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:22 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 12:03:38 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// VERSAO COM ERRO DE LOCK
// void eat(t_rules *rules, t_philo *philo)
// {
// 	pthread_mutex_lock(&rules->m_forks[philo->left_fork]);
// 	lock_print(rules, philo->id, "has taken a fork");
// 	if (rules->num_philosophers == 1)
// 	{
// 		pthread_mutex_unlock(&rules->m_forks[philo->left_fork]);
// 		smart_sleep(rules->time_to_die * 2);
// 		return;
// 	}
// 	pthread_mutex_lock(&rules->m_forks[philo->right_fork]);
// 	lock_print(rules, philo->id, "has taken a fork");

// 	pthread_mutex_lock(&rules->m_check);
// 	lock_print(rules, philo->id, "is eating");
// 	philo->last_meal = timestamp();
// 	philo->times_eaten++;
// 	if (philo->times_eaten == rules->num_times_eat)
// 		rules->all_satisfied++;
// 	pthread_mutex_unlock(&rules->m_check);
// 	smart_sleep(rules->time_to_eat);

// 	pthread_mutex_unlock(&rules->m_forks[philo->right_fork]);
// 	pthread_mutex_unlock(&rules->m_forks[philo->left_fork]);
// }

// VERSAO SEM ERRO DE LOCK
void eat(t_rules *rules, t_philo *philo)
{
	int left_fork = philo->left_fork;
	int right_fork = philo->right_fork;

	if (left_fork > right_fork)
	{
		int temp = left_fork;
		left_fork = right_fork;
		right_fork = temp;
	}

	pthread_mutex_lock(&rules->m_forks[left_fork]);
	lock_print(rules, philo->id, "has taken a fork");
	if (rules->num_philosophers == 1)
	{
		pthread_mutex_unlock(&rules->m_forks[left_fork]);
		smart_sleep(rules->time_to_die * 2);
		return;
	}
	pthread_mutex_lock(&rules->m_forks[right_fork]);
	lock_print(rules, philo->id, "has taken a fork");

	pthread_mutex_lock(&rules->m_check);
	lock_print(rules, philo->id, "is eating");
	philo->last_meal = timestamp();
	philo->times_eaten++;
	if (philo->times_eaten == rules->num_times_eat)
		rules->all_satisfied++;
	pthread_mutex_unlock(&rules->m_check);
	smart_sleep(rules->time_to_eat);

	pthread_mutex_unlock(&rules->m_forks[right_fork]);
	pthread_mutex_unlock(&rules->m_forks[left_fork]);
}

void sleeping_and_thinking(t_rules *rules, t_philo *philo)
{
	lock_print(rules, philo->id, "is sleeping");
	smart_sleep(rules->time_to_sleep);
	lock_print(rules, philo->id, "is thinking");
}

// VERSAO COM A FUNÇÃO QUEBRADA EM FUNÇÕES MENORES
// int get_left_fork(t_philo *philo)
// {
// 	int left_fork = philo->left_fork;
// 	int right_fork = philo->right_fork;

// 	if (left_fork > right_fork)
// 	{
// 		int temp = left_fork;
// 		left_fork = right_fork;
// 		right_fork = temp;
// 	}

// 	return left_fork;
// }

// int get_right_fork(t_philo *philo)
// {
// 	int left_fork = philo->left_fork;
// 	int right_fork = philo->right_fork;

// 	if (left_fork > right_fork)
// 	{
// 		int temp = left_fork;
// 		left_fork = right_fork;
// 		right_fork = temp;
// 	}

// 	return right_fork;
// }

// void acquire_forks(t_rules *rules, int left_fork, int right_fork)
// {
// 	pthread_mutex_lock(&rules->m_forks[left_fork]);
// 	lock_print(rules, rules->philo->id, "has taken a fork");
// 	if (rules->num_philosophers == 1)
// 	{
// 		pthread_mutex_unlock(&rules->m_forks[left_fork]);
// 		smart_sleep(rules->time_to_die * 2);
// 		return;
// 	}
// 	pthread_mutex_lock(&rules->m_forks[right_fork]);
// 	lock_print(rules, rules->philo->id, "has taken a fork");
// }

// void release_forks(t_rules *rules, int left_fork, int right_fork)
// {
// 	pthread_mutex_unlock(&rules->m_forks[right_fork]);
// 	pthread_mutex_unlock(&rules->m_forks[left_fork]);
// }

// void eat(t_rules *rules, t_philo *philo)
// {
// 	int left_fork = get_left_fork(philo);
// 	int right_fork = get_right_fork(philo);

// 	acquire_forks(rules, left_fork, right_fork);

// 	lock_print(rules, philo->id, "is eating");
// 	philo->last_meal = timestamp();
// 	philo->times_eaten++;
// 	if (philo->times_eaten == rules->num_times_eat)
// 		rules->all_satisfied++;
// 	smart_sleep(rules->time_to_eat);

// 	release_forks(rules, left_fork, right_fork);
// }
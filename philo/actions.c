/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:22 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 22:59:06 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->m_forks[philo->left_fork]);
	lock_print(rules, philo->id, "has taken a fork");
	if (rules->num_philosophers == 1)
	{
		pthread_mutex_unlock(&rules->m_forks[philo->left_fork]);
		smart_sleep(rules->time_to_die * 2);
		return;
	}
	pthread_mutex_lock(&rules->m_forks[philo->right_fork]);
	lock_print(rules, philo->id, "has taken a fork");

	pthread_mutex_lock(&rules->m_check);
	lock_print(rules, philo->id, "is eating");
	philo->last_meal = timestamp();
	philo->times_eaten++;
	if (philo->times_eaten == rules->num_times_eat)
		rules->all_satisfied++;
	smart_sleep(rules->time_to_eat);
	pthread_mutex_unlock(&rules->m_check);

	pthread_mutex_unlock(&rules->m_forks[philo->left_fork]);
	pthread_mutex_unlock(&rules->m_forks[philo->right_fork]);
}

void sleeping_and_thinking(t_rules *rules, t_philo *philo)
{
	lock_print(rules, philo->id, "is sleeping");
	smart_sleep(rules->time_to_sleep);
	lock_print(rules, philo->id, "is thinking");
}

int check_finish(t_rules *rules)
{
	pthread_mutex_lock(&rules->m_finish);
	if (rules->finish)
	{
		pthread_mutex_unlock(&rules->m_finish);
		return (1);
	}
	pthread_mutex_unlock(&rules->m_finish);
	return (0);
}
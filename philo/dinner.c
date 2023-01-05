/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:42 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 22:59:11 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *dinner(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;

	if (philo->id % 1 && philo->rules->num_philosophers > 1)
		usleep(philo->rules->time_to_eat);
	while (1)
	{
		if (check_finish(philo->rules))
			break;
		eat(philo->rules, philo);
		sleeping_and_thinking(philo->rules, philo);
	}
	return (NULL);
}

void waiter(t_rules *rules)
{
	pthread_mutex_lock(&rules->m_check);
	if (rules->all_satisfied == rules->num_philosophers)
	{
		pthread_mutex_lock(&rules->m_finish);
		rules->finish = 1;
		pthread_mutex_unlock(&rules->m_finish);
	}
	pthread_mutex_unlock(&rules->m_check);
}

void *monitor(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_finish(philo->rules))
			break;
		waiter(philo->rules);
		pthread_mutex_lock(&philo->rules->m_check);
		if (!philo->rules->finish && timestamp() -
											 philo->last_meal >
										 philo->rules->time_to_die)
		{
			lock_print(philo->rules, philo->id, "died");
			pthread_mutex_lock(&philo->rules->m_finish);
			philo->rules->finish = 1;
			pthread_mutex_unlock(&philo->rules->m_finish);
		}
		pthread_mutex_unlock(&philo->rules->m_check);
		usleep(100);
	}
	return (NULL);
}
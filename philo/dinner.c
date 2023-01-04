/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:42 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 12:05:06 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)arg;
	rules = philo->rules;
	if (philo->id % 2 && rules->num_philosophers > 1)
		usleep(rules->time_to_eat);
	while (1)
	{
		if (check_finish(rules))
			break ;
		take_fork(rules, philo);
		eat(rules, philo);
		sleeping_and_thinking(rules, philo);
	}
	return (NULL);
}

int	check_finish(t_rules *rules)
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

void	waiter(t_rules *rules)
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

void	*monitor(void *arg)
{
	t_rules	*rules;

	rules = (t_rules *)arg;
	while (1)
	{
		if (check_finish(rules))
			break ;
		waiter(rules);
		pthread_mutex_lock(&rules->m_check);
		if (!rules->finish && timestamp() - \
				rules->philo->last_meal > rules->time_to_die)
		{
			lock_print(rules, rules->philo->id, "died");
			pthread_mutex_lock(&rules->m_finish);
			rules->finish = 1;
			pthread_mutex_unlock(&rules->m_finish);
		}
		pthread_mutex_unlock(&rules->m_check);
		usleep(100);
	}
	return (NULL);
}

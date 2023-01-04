/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:42 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 08:53:19 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *dinner(void *arg)
{
    t_philo *philo;
    t_rules *rules;

    philo = (t_philo *)arg;
    rules = philo->rules;
    if (philo->id % 2 && rules->num_philosophers > 1)
        usleep(rules->time_to_eat);
    while (1)
    {
        pthread_mutex_lock(&rules->m_finish);
        if (rules->finish)
        {
            pthread_mutex_unlock(&rules->m_finish);
            break;
        }
        pthread_mutex_unlock(&rules->m_finish);
        take_fork(rules, philo);
        eat(rules, philo);
        sleeping_and_thinking(rules, philo);
    }
    return (NULL);
}

void *waiter(void *arg)
{
    t_rules *rules = (t_rules *)arg;

    while (1)
    {
        pthread_mutex_lock(&rules->m_finish);
        if (rules->finish)
        {
            pthread_mutex_unlock(&rules->m_finish);
            break;
        }
        pthread_mutex_unlock(&rules->m_finish);

        pthread_mutex_lock(&rules->m_check);
        if (rules->all_satisfied == rules->num_philosophers)
        {
            pthread_mutex_lock(&rules->m_finish);
            rules->finish = 1;
            pthread_mutex_unlock(&rules->m_finish);
        }
        pthread_mutex_unlock(&rules->m_check);

        pthread_mutex_lock(&rules->m_check);
        if (!rules->finish && timestamp() - rules->philo->last_meal > rules->time_to_die)
        {
            lock_print(rules, rules->philo->id, "died");
            pthread_mutex_lock(&rules->m_finish);
            rules->finish = 1;
            pthread_mutex_unlock(&rules->m_finish);
        }
        pthread_mutex_unlock(&rules->m_check);
        usleep(100);
    }
    return NULL;
}
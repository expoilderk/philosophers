/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:42 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/03 20:46:44 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que simula a comida de um filósofo
void *dinner(void *arg)
{
    t_philo *philo;
    t_rules *rules;

    philo = (t_philo *)arg;
    rules = philo->rules;
    if (philo->id % 2)
        usleep(rules->time_to_eat * 1000);
    while (!rules->finish)
    {
        take_fork(rules, philo);
        eat(rules, philo);
        // put_fork(rules, philo);
        sleeping_and_thinking(rules, philo);
    }
    return (NULL);
}

void *waiter(void *arg)
{
    t_rules *rules = (t_rules *)arg;

    while (!rules->finish)
    {
        pthread_mutex_lock(&rules->m_finish);
        if (rules->all_satisfied == rules->num_philosophers)
            rules->finish = 1;
        pthread_mutex_unlock(&rules->m_finish);

        pthread_mutex_lock(&rules->m_check);
        pthread_mutex_lock(&rules->m_finish);
        if (!rules->finish && timestamp() - rules->philo->last_meal > rules->time_to_die)
        {
            lock_print(rules, rules->philo->id, "died");
            rules->finish = 1;
        }
        pthread_mutex_unlock(&rules->m_check);
        pthread_mutex_unlock(&rules->m_finish);
        usleep(100);
    }
    return NULL;
}
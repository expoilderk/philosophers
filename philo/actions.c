/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:22 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/22 16:44:01 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_fork(t_rules *rules, t_philo *philo)
{
    pthread_mutex_lock(&rules->forks[philo->left_fork]);
    lock_print(rules, philo->id, "has taken a fork");
    pthread_mutex_lock(&rules->forks[philo->right_fork]);
    lock_print(rules, philo->id, "has taken a fork");
}

void eat(t_rules *rules, t_philo *philo)
{
    lock_print(rules, philo->id, "is eating");
    philo->last_meal = timestamp();
    philo->times_eaten++;
    usleep(rules->time_to_eat * 1000);
}

void put_fork(t_rules *rules, t_philo *philo)
{
    pthread_mutex_unlock(&rules->forks[philo->left_fork]);
    pthread_mutex_unlock(&rules->forks[philo->right_fork]);
}

void sleeping_and_thinking(t_rules *rules, t_philo *philo)
{
    lock_print(rules, philo->id, "is sleeping");
    usleep(rules->time_to_sleep * 1000);
    lock_print(rules, philo->id, "is thinking");
}

// Provavelmente não está totalmente certo, porque preciso verificar 
// o tempo todo cada filósofo e essa função não faz isso ainda
int someone_died(t_rules *rules, t_philo *philo)
{
    if((timestamp() - philo->last_meal) > rules->time_to_die)
    {
        lock_print(rules, philo->id, "died");
        rules->someone_died = 1;
        return (1);
    }
    return (0);
}

// Função não está funcional
int all_satisfied(t_rules *rules, t_philo *philo)
{
    if(philo->times_eaten == rules->num_times_eat)
        rules->all_satisfied++;
    if(rules->all_satisfied == rules->num_philosophers)
        return (1);
    else
        return (0);
}
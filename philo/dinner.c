/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:42 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/22 11:11:48 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função apenas de teste, remover depois
void *test_thread(void *arg)
{
    t_philo *philo;
    t_rules *rules;

    philo = (t_philo *)arg;
    rules = philo->rules;


    while (philo->times_eaten != rules->num_times_eat)
    {
        // pthread_mutex_lock(&rules->forks[philo->left_fork]);
        // lock_print(rules, philo->id, "has taken a fork");
        // pthread_mutex_lock(&rules->forks[philo->right_fork]);
        // lock_print(rules, philo->id, "has taken a fork");
        

        lock_print(rules, philo->id, "is eating");
        philo->times_eaten++;
        usleep(1000);

        // pthread_mutex_unlock(&rules->forks[philo->left_fork]);
        // pthread_mutex_unlock(&rules->forks[philo->right_fork]);

        lock_print(rules, philo->id, "is sleeping");
        usleep(1000);

        lock_print(rules, philo->id, "is thinking");
        usleep(1000);
    }

    return (NULL);
}

// Modelo de código para a função dinner
/*
* dinner() {
    while (!someone_die() && !all_satisfied()) {
        take_fork();
        eat();
        put_fork();
        sleep();
        think();
    }
}
*/

// Modelo de código para a função waiter
/*
* waiter() {
    someone_die();
    all_satisfied();
}
*/

// Função que simula a comida de um filósofo
void *dinner(void *arg)
{
    (void)arg;

    /*
    t_rules *dinner = (t_rules *)arg;

        while (!someone_die() && !all_satisfied())
        {
            take_fork();
            eat();
            put_fork();
            sleep();
            think();
        }
    */
    return NULL;
}

void *waiter(void *arg)
{
    (void)arg;

    // someone_die();
    // all_satisfied();

    return NULL;
}
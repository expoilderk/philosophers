/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:42 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/22 16:48:22 by mreis-me         ###   ########.fr       */
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

    // while (all_satisfied(rules, philo) == 0)

    // Só leva em consideração as vezes que cada um comeu, 
    // falta verificar a morte e fazer isso em duas funções especificas
    while (philo->times_eaten != rules->num_times_eat)
    {
        if(philo->id % 2)
            usleep(100);
        take_fork(rules, philo);
        eat(rules, philo);
        put_fork(rules, philo);
        sleeping_and_thinking(rules, philo);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:42 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/21 09:10:58 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função apenas de teste, remover depois
void *test_thread(void *arg)
{
    (void)arg;
    t_philo *philo = (t_philo *)arg;

    lock_print(philo->id, "is thinking");
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
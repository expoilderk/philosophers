/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:42 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/12 20:19:47 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
    t_table *dinner = (t_table *)arg;

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
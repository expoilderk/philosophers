/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:42 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/02 01:43:24 by mreis-me         ###   ########.fr       */
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
    // while (philo->times_eaten != rules->num_times_eat)
    while (!rules->someone_died)
    {
        if (philo->id % 2)
            usleep(rules->time_to_eat * 1000);
        take_fork(rules, philo);
        eat(rules, philo);
        put_fork(rules, philo);
        if (rules->all_satisfied)
            break;
        sleeping_and_thinking(rules, philo);
        waiter(rules, philo);
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

// void *waiter(void *arg)
// {
//     (void)arg;

//     // someone_die();
//     // all_satisfied();

//     return NULL;
// }

// void *waiter(void *arg)
// {
//     t_rules *rules = (t_rules *)arg;

//     while (1)
//     {
//         // Verifica se algum filósofo morreu
//         int i = 0;
//         while (i < rules->num_philosophers)
//         {
//             if (someone_died(rules, &rules->philo[i]))
//             {
//                 rules->someone_died = 1;
//                 break;
//             }
//             i++;
//         }

//         // Verifica se todos os filósofos estão satisfeitos
//         rules->all_satisfied = 1;
//         i = 0;
//         while (i < rules->num_philosophers)
//         {
//             if (!all_satisfied(rules, &rules->philo[i]))
//             {
//                 rules->all_satisfied = 0;
//                 break;
//             }
//             i++;
//         }

//         // Se algum filósofo morreu ou todos os filósofos estão satisfeitos, encerra a thread_philo
//         if (rules->someone_died || rules->all_satisfied)
//         {
//             break;
//         }
//     }
//     pthread_exit(0);
// }

void waiter(t_rules *rules, t_philo *philo)
{
    int i;

    while (!rules->all_satisfied)
    {
        i = 0;
        while (i < rules->num_philosophers && !rules->someone_died)
        {
            if (time_diff(philo[i].last_meal, timestamp()) > rules->time_to_die)
            {
                lock_print(rules, philo->id, "died");
                rules->someone_died = 1;
            }
            i++;
        }
        if (rules->someone_died)
            break;
        i = 0;
        while (i < rules->num_philosophers && philo[i].times_eaten >= rules->num_times_eat)
            i++;
        if (i == rules->num_philosophers)
            rules->all_satisfied = 1;
    }
}

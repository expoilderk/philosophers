/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:35 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/19 18:33:35 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que imprime de maneira segura
void lock_print(int id, char *string)
{
    // get_time_now();
    t_rules rules;

    int ms = 100 + id;

    pthread_mutex_lock(&rules.print);
    printf("%d %d %s\n", ms, id, string);
    pthread_mutex_unlock(&rules.print);
}

void *test_thread(void *arg)
{
    // t_rules *rules = (t_rules *)arg;
    t_philo *philo = (t_philo *)arg;

    lock_print(philo->id, "is thinking");
    return (NULL);
}
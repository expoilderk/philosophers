/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:35 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/12 20:13:38 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que imprime de maneira segura
// void *lock_print(char *arg, t_philo *philo);
void *lock_print(void *arg)
{
    // get_time_now();

    t_philo *philo = (t_philo *)arg;

    // pthread_mutex_lock();
    printf("id: %d\n", philo->id);
    // pthread_mutex_unlock();

    return NULL;
}
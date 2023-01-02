/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:28 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/02 00:36:16 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 *  Essa função retorna o tempo atual em milissegundos.
 */
long timestamp()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/**
 *  Essa função tira a diferença entre dois timestamps em milissegundos.
 */
long time_diff(long start, long end)
{
    return (end - start);
}

/**
 *  Essa função retorna o tempo atual em milissegundos.
 */
void sleep_ms(int ms)
{
    long int time;

    time = timestamp();
    // while (time_diff(timestamp(), time) < ms)
    //     usleep(ms / 10);
    while (timestamp() - time < ms)
        usleep(ms / 10);
}

/**
 *  Essa função calcula o tempo transcorrido em milissegundos entre um
 *  timestamp especificado como argumento e o tempo atual.
 */
long time_travelled(struct timeval timestamp)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec - timestamp.tv_sec) * 1000 + (current_time.tv_usec - timestamp.tv_usec) / 1000;
}

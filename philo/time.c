/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:28 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/21 22:50:21 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 *  Essa função retorna o tempo atual em milissegundos.
 */
long current_time()
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
 *  Essa função calcula o tempo transcorrido em milissegundos entre um
 *  timestamp especificado como argumento e o tempo atual.
 */
long time_travelled(long timestamp)
{
    long ms;
    ms = current_time();
    return (time_diff(ms, timestamp));
}

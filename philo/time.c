/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:28 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 00:18:19 by mreis-me         ###   ########.fr       */
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
// void smart_sleep(long time, t_rules *rules)
// {
//     long start;

//     start = timestamp();
//     while (!rules->finish)
//     {
//         if (time_diff(start, timestamp()) >= time)
//             break;
//         usleep(50);
//     }
// }

void smart_sleep(int time, t_rules *rules)
{
    long int start;

    start = timestamp();

    while (timestamp() - start < time)
    {
        usleep(time / 10);
        pthread_mutex_lock(&rules->m_finish);
        if (rules->finish)
        {
            pthread_mutex_unlock(&rules->m_finish);
            break;
        }
        pthread_mutex_unlock(&rules->m_finish);
    }
}

void ft_usleep(int ms)
{
    long int time;

    time = timestamp();
    while (timestamp() - time < ms)
        usleep(ms / 10);
}
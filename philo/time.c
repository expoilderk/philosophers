/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:28 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/21 09:52:49 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 *  Essa função retorna o tempo atual em milissegundos.
 */
long get_current_time()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/**
 *  Essa função calcula o tempo transcorrido em milissegundos entre um
 *  timestamp especificado como argumento e o tempo atual.
 */
long get_time_travelled(struct timeval timestamp)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec - timestamp.tv_sec) * 1000 + (current_time.tv_usec - timestamp.tv_usec) / 1000;
}

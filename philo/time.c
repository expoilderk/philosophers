/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:28 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/19 18:33:09 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*long get_time_now()
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec - timestamp.tv_sec) * 1000 + (current_time.tv_usec - timestamp.tv_usec) / 1000;
}*/

long get_time(struct timeval timestamp)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec - timestamp.tv_sec) * 1000 + (current_time.tv_usec - timestamp.tv_usec) / 1000;
}

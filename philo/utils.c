/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:35 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/31 16:51:54 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que imprime de maneira segura
void lock_print(t_rules *rules, int id, char *string)
{
    pthread_mutex_lock(&rules->print);
    printf("%ld %d %s\n", timestamp() - rules->start_time, id, string);
    pthread_mutex_unlock(&rules->print);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:35 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/21 09:52:58 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que imprime de maneira segura
void lock_print(int id, char *string)
{
    t_rules rules;
    // long ms;

    // ms = get_current_time();
    pthread_mutex_lock(&rules.print);
    printf("%li %i %s\n", get_time_travelled(rules.start_time), id, string);
    pthread_mutex_unlock(&rules.print);
}
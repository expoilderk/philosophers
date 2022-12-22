/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:35 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/21 22:49:47 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que imprime de maneira segura
void lock_print(int id, char *string)
{
    t_rules rules;

    pthread_mutex_lock(&rules.print);
    printf("%li %i %s\n", time_travelled(rules.start_time), id, string);
    // printf("%li %i %s\n", current_time() - rules.start_time, id, string);
    pthread_mutex_unlock(&rules.print);
}
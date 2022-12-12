/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:32 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/12 20:17:15 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    // Checa se o número de argumentos está correto
    if (argc < 5 || argc > 6)
    {
        help_msg();
        return (0);
    }

    // Lê os argumentos da linha de comando
    /*    int num_philosophers = atoi(argv[1]);
        int time_to_die = atoi(argv[2]);
        int time_to_eat = atoi(argv[3]);
        int time_to_sleep = atoi(argv[4]);
        int num_times_eat = (argc == 6) ? atoi(argv[5]) : 0;
    */
    return (0);
}
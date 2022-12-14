/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:08 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/13 21:27:40 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Ficar atento para não ter problemas pelo fato do retorno da função ser void
 */

// função init
t_table init(int argc, char **argv)
{
    t_table table;

    // Inicializa a mesa
    init_table(argc, argv, &table);

    // Inicializa os filósofos
    init_philo(&table);

    // Inicializa os garfos
    init_forks(&table);

    return (table);
}

// função que inicializa a mesa
void init_table(int argc, char **argv, t_table *table)
{
    // Inicializa os dados da mesa
    table->num_philosophers = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        table->num_times_eat = ft_atoi(argv[5]);
    else
        table->num_times_eat = 0;
}

// função que inicializa os filósofos
void init_philo(t_table *table)
{
    int i = 0;
    // Aloca memória para os filósofos
    table->philo = malloc(sizeof(t_philo) * table->num_philosophers);

    // Inicializa os dados para cada filósofo
    while (i < table->num_philosophers)
    {
        table->philo[i].id = i;
        table->philo[i].times_eaten = 0;
        table->philo[i].last_meal = 0;

        // Cria as threads para cada filósofo
        pthread_create(&table->philo[i].thread, NULL, lock_print, &table->philo[i]);
        i++;
    }
}

// função que inicializa os mutexes dos garfos
void init_forks(t_table *table)
{
    int i = 0;

    // Aloca memória para os garfos
    table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philosophers);

    // Inicializa mutexes para os garfos
    while (i < table->num_philosophers)
        pthread_mutex_init(&table->forks[i++], NULL);
}

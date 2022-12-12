/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:08 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/12 20:13:10 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Ficar atento para não ter problemas pelo fato do retorno da função ser void
 */

// função init
void init(int argc, char **argv, t_table *table)
{
    // Inicializa a mesa
    init_table(argc, argv, table);

    // Inicializa os filósofos
    init_philo(table, table->philo);

    // Inicializa os garfos
    init_forks(table);
}

// função que inicializa a mesa
void init_table(int argc, char **argv, t_table *table)
{
    // Lê os argumentos da linha de comando
    int num_philosophers = atoi(argv[1]);
    int time_to_die = atoi(argv[2]);
    int time_to_eat = atoi(argv[3]);
    int time_to_sleep = atoi(argv[4]);
    int num_times_eat = (argc == 6) ? atoi(argv[5]) : 0;

    // Inicializa os dados da mesa
    table->num_philosophers = num_philosophers;
    table->time_to_die = time_to_die;
    table->time_to_eat = time_to_eat;
    table->time_to_sleep = time_to_sleep;
    table->num_times_eat = num_times_eat;
}

// função que inicializa os filósofos
void init_philo(t_table *table, t_philo *philo)
{
    int i = 0;
    // Aloca memória para os filósofos
    table->philo = malloc(sizeof(t_philo) * table->num_philosophers);

    // Inicializa os dados para cada filósofo
    while (i < table->num_philosophers)
    {
        philo->id = i;
        philo->times_eaten = 0;
        philo->last_meal = 0;

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
    {
        pthread_mutex_init(&table->forks[i++], NULL);
    }
}

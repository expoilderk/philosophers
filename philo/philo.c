/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:11:26 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/12 20:20:03 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    // Inicializa a mesa
    t_table table;

    // Checa se o número de argumentos está correto
    if (argc < 5 || argc > 6)
    {
        printf("Uso: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
        return (0);
    }

    // Lê os argumentos da linha de comando
    int num_philosophers = atoi(argv[1]);
    int time_to_die = atoi(argv[2]);
    int time_to_eat = atoi(argv[3]);
    int time_to_sleep = atoi(argv[4]);
    int num_times_eat = (argc == 6) ? atoi(argv[5]) : 0;

    // Inicializa os dados da mesa
    table.num_philosophers = num_philosophers;
    table.time_to_die = time_to_die;
    table.time_to_eat = time_to_eat;
    table.time_to_sleep = time_to_sleep;
    table.num_times_eat = num_times_eat;

    // Aloca memória para os filósofos e garfos
    table.philo = malloc(sizeof(t_philo) * num_philosophers);
    table.forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);

    // Inicializa mutexes para os garfos
    int i = 0;
    while (i < num_philosophers)
    {
        pthread_mutex_init(&table.forks[i++], NULL);
    }

    // Inicializa os dados para cada filósofo
    for (int i = 0; i < num_philosophers; i++)
    {
        table.philo[i].id = i;
        table.philo[i].times_eaten = 0;
        table.philo[i].last_meal = 0;
    }

    // Cria threads para filósofos
    for (int i = 0; i < num_philosophers; i++)
    {
        pthread_create(&table.philo[i].thread, NULL, lock_print, &table.philo[i]);
        // pthread_create(&dinner.philo[i].thread, NULL, dinner_routine, &dinner);
    }

    // Aguarda as threads dos filósofos terminarem
    for (int i = 0; i < num_philosophers; i++)
    {
        pthread_join(table.philo[i].thread, NULL);
    }

    // Limpa os mutexes dos garfos
    for (int i = 0; i < num_philosophers; i++)
    {
        pthread_mutex_destroy(&table.forks[i]);
    }

    // Libera a memória alocada
    free(table.philo);
    free(table.forks);

    return 0;
}

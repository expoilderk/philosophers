/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:11:26 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/11 22:26:38 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// check args
// error
// init_philo
// create_mutexes
// create_threads
// join_threads
// free

int main(int argc, char **argv)
{
    // Inicializa a mesa
    t_table dinner;

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
    dinner.num_philosophers = num_philosophers;
    dinner.time_to_die = time_to_die;
    dinner.time_to_eat = time_to_eat;
    dinner.time_to_sleep = time_to_sleep;
    dinner.num_times_eat = num_times_eat;

    // Aloca memória para os filósofos
    dinner.philo = malloc(sizeof(t_philo) * num_philosophers);
    dinner.forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);

    // Inicializa mutexes para os garfos
    for (int i = 0; i < num_philosophers; i++)
    {
        pthread_mutex_init(&dinner.forks[i], NULL);
    }

    // Cria threads para filósofos
    for (int i = 0; i < num_philosophers; i++)
    {
        // Inicializa os dados para cada filósofo
        dinner.philo[i].id = i;
        dinner.philo[i].times_eaten = 0;
        dinner.philo[i].last_meal = 0;
        // Cria a thread para o filósofo
        pthread_create(&dinner.philo[i].thread, NULL, dinner_routine, &dinner.philo[i]);
    }
    // Aguarda as threads dos filósofos terminarem
    for (int i = 0; i < num_philosophers; i++)
    {
        pthread_join(dinner.philo[i].thread, NULL);
    }
    // Limpa os mutexes dos garfos
    for (int i = 0; i < num_philosophers; i++)
    {
        pthread_mutex_destroy(&dinner.forks[i]);
    }
    return 0;
}

// função que inicializa os filósofos
/*void init_philo(t_philo *philo, int id, int forks, int time_to_die, int time_to_eat, int time_to_sleep, int num_times_eat)
{
    philo->id = id;
    philo->forks = forks;
    philo->time_to_die = time_to_die;
    philo->time_to_eat = time_to_eat;
    philo->time_to_sleep = time_to_sleep;
    philo->num_times_eat = num_times_eat;
    philo->times_eaten = 0;
    philo->last_meal = 0;
}*/
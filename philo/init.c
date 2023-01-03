/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:08 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/03 18:36:54 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Ficar atento para não ter problemas pelo fato do retorno da função ser void
 */

// função init
void init(char **argv, t_rules *rules)
{
    // Guarda o tempo inicial
    rules->start_time = timestamp();

    // Inicializa a mesa
    init_rules(argv, rules);

    // Inicializa os garfos
    init_mutex(rules);

    // Inicializa os filósofos
    init_threads(rules);

    // Inicializa o waiter
    // init_waiter(rules);
}

// função que inicializa a mesa
void init_rules(char **argv, t_rules *rules)
{
    // Inicializa os dados das regras
    rules->num_philosophers = ft_atoi(argv[1]);
    rules->time_to_die = ft_atoi(argv[2]);
    rules->time_to_eat = ft_atoi(argv[3]);
    rules->time_to_sleep = ft_atoi(argv[4]);
    rules->finish = 0;
    rules->all_satisfied = 0;
    rules->someone_died = 0;
    if (argv[5])
        rules->num_times_eat = ft_atoi(argv[5]);
    else
        rules->num_times_eat = -1;
}

// função que inicializa os filósofos
void init_threads(t_rules *rules)
{
    int i;
    pthread_t thread_waiter;

    // Aloca memória para os filósofos
    rules->philo = malloc(sizeof(t_philo) * rules->num_philosophers);

    // Inicializa os dados para cada filósofo
    i = 0;
    while (i < rules->num_philosophers)
    {
        rules->philo[i].id = i + 1;
        rules->philo[i].left_fork = i;
        rules->philo[i].right_fork = (i + 1) % rules->num_philosophers;
        rules->philo[i].times_eaten = 0;
        rules->philo[i].rules = rules;

        // Cria as threads para cada filósofo (Criar uma função especifica init_threads?)
        pthread_create(&rules->philo[i].thread_philo, NULL, dinner, &rules->philo[i]);
        rules->philo[i].last_meal = timestamp();

        // Cria a thread do garçom
        pthread_create(&thread_waiter, NULL, waiter, rules);
        pthread_detach(thread_waiter);
        i++;
    }
}

// função que inicializa os mutexes dos garfos
void init_mutex(t_rules *rules)
{
    int i;

    // Aloca memória para os garfos
    rules->m_forks = malloc(sizeof(pthread_mutex_t) * rules->num_philosophers);

    // Inicializa mutexes para os garfos
    i = 0;
    while (i < rules->num_philosophers)
        pthread_mutex_init(&rules->m_forks[i++], NULL);

    pthread_mutex_init(&rules->m_print, NULL);
    pthread_mutex_init(&rules->m_check, NULL);
    pthread_mutex_init(&rules->m_finish, NULL);
}

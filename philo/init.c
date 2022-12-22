/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:08 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/22 11:13:49 by mreis-me         ###   ########.fr       */
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

    // Inicializa os filósofos
    init_philo(rules);

    // Inicializa os garfos
    init_mutex(rules);
}

// função que inicializa a mesa
void init_rules(char **argv, t_rules *rules)
{
    // Inicializa os dados das regras
    rules->num_philosophers = ft_atoi(argv[1]);
    rules->time_to_die = ft_atoi(argv[2]);
    rules->time_to_eat = ft_atoi(argv[3]);
    rules->time_to_sleep = ft_atoi(argv[4]);
    rules->all_satisfied = 0;
    rules->someone_died = 0;
    if (argv[5])
        rules->num_times_eat = ft_atoi(argv[5]);
    else
        rules->num_times_eat = -1;
}

// função que inicializa os filósofos
void init_philo(t_rules *rules)
{
    int i = 0;
    // Aloca memória para os filósofos
    rules->philo = malloc(sizeof(t_philo) * rules->num_philosophers);

    // Inicializa os dados para cada filósofo
    while (i < rules->num_philosophers)
    {
        rules->philo[i].id = i + 1;
        rules->philo[i].left_fork = i;
        rules->philo[i].right_fork = (i + 1) % rules->num_philosophers;
        rules->philo[i].times_eaten = 0;
        rules->philo[i].last_meal = 0;
        rules->philo[i].rules = rules;
        
        // Cria as threads para cada filósofo
        pthread_create(&rules->philo[i].thread, NULL, test_thread, &rules->philo[i]);
        i++;
    }
}

// função que inicializa os mutexes dos garfos
void init_mutex(t_rules *rules)
{
    int i = 0;

    // Aloca memória para os garfos
    rules->forks = malloc(sizeof(pthread_mutex_t) * rules->num_philosophers);

    // Inicializa mutexes para os garfos
    while (i < rules->num_philosophers)
        pthread_mutex_init(&rules->forks[i++], NULL);

    pthread_mutex_init(&rules->print, NULL);
}

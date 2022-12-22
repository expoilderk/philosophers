/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:22 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/22 15:18:35 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_fork(t_rules *rules, t_philo *philo)
{
    pthread_mutex_lock(&rules->forks[philo->left_fork]);
    lock_print(rules, philo->id, "has taken a fork");
    pthread_mutex_lock(&rules->forks[philo->right_fork]);
    lock_print(rules, philo->id, "has taken a fork");
}

void eat(t_rules *rules, t_philo *philo)
{
    lock_print(rules, philo->id, "is eating");
    philo->last_meal = timestamp();
    philo->times_eaten++;
    usleep(rules->time_to_eat * 1000);
}

void put_fork(t_rules *rules, t_philo *philo)
{
    pthread_mutex_unlock(&rules->forks[philo->left_fork]);
    pthread_mutex_unlock(&rules->forks[philo->right_fork]);
}

void sleeping_and_thinking(t_rules *rules, t_philo *philo)
{
    lock_print(rules, philo->id, "is sleeping");
    usleep(rules->time_to_sleep * 1000);
    lock_print(rules, philo->id, "is thinking");
}

/* FUNÇÃO PARA SER DESMEMBRADA EM OUTRAS FUNÇÕES DE AÇÃO
void *dinner(void *arg)
{
    t_rules *dinner = (t_rules *)arg;
    int id = dinner->philo->id;
    int num_philo = dinner->num_philosophers;

    int left_fork = id;
    int right_fork = (id + 1) % num_philo;

    // Inicializa o timestamp para o início da simulação
    struct timeval timestamp;
    gettimeofday(&timestamp, NULL);

    while (1)
    {
        // Calcula o timestamp atual
        long time_since_start = get_time(timestamp);

        // Verifica se o filósofo morreu
        if (time_since_start > dinner->time_to_die)
        {
            printf("%ld %d died\n", time_since_start, id);
            pthread_exit(NULL);
        }

        // Try to pick up forks
        if (pthread_mutex_lock(&dinner->forks[left_fork]) == 0 && pthread_mutex_lock(&dinner->forks[right_fork]) == 0)
        {
            printf("%ld %d has taken a fork\n", time_since_start, id);
            printf("%ld %d has taken a fork\n", time_since_start, id);
        }

        // Eat
        printf("%ld %d is eating\n", time_since_start, id);
        // usleep(philosopher->time_to_eat * 1000);
        dinner->philo->times_eaten++;

        // Put down forks
        pthread_mutex_unlock(&dinner->forks[left_fork]);
        pthread_mutex_unlock(&dinner->forks[right_fork]);

        // Verifica se o filósofo já comeu o suficiente e deve parar
        if (dinner->num_times_eat > 0 && dinner->philo->times_eaten >= dinner->num_times_eat)
        {
            pthread_exit(NULL);
        }

        // Sleep
        printf("%ld %d is sleeping\n", time_since_start, id);
        usleep(dinner->time_to_sleep * 1000);

        // Think
        printf("%ld %d is thinking\n", time_since_start, id);
        // usleep(philosopher->time_to_sleep * 1000);
    }
}
*/
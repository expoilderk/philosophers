/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:35 by mreis-me          #+#    #+#             */
/*   Updated: 2022/12/13 21:27:34 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Função que imprime de maneira segura
// void *lock_print(char *arg, t_philo *philo);
void *lock_print(void *arg)
{
    // get_time_now();

    // t_table *table = (t_table *)arg;
    t_philo *philo = (t_philo *)arg;

    // pthread_mutex_lock();
    // printf("id: %d\n", table->philo->id);
    printf("id: %d\n", philo->id);
    // pthread_mutex_unlock();

    return NULL;
}

int ft_atoi(const char *str)
{
    int sum;
    int i;
    int sign;

    sum = 0;
    i = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        sum = (sum * 10) + (str[i] - '0');
        i++;
    }
    return (sign * sum);
}

long int ft_atoi_l(const char *str)
{
    long int sum;
    int i;
    int sign;

    sum = 0;
    i = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        sum = (sum * 10) + (str[i] - '0');
        i++;
    }
    return (sign * sum);
}

int ft_isdigit(int c)
{
    if (c >= 48 && c <= 57)
        return (2048);
    return (0);
}

int ft_issign(char c)
{
    if (c == '+' || c == '-')
        return (1);
    return (0);
}
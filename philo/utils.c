/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:13:35 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 11:25:52 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_print(t_rules *rules, int id, char *string)
{
	pthread_mutex_lock(&rules->m_print);
	pthread_mutex_lock(&rules->m_finish);
	if (!rules->finish)
		printf("%ld %d %s\n", timestamp() - rules->start_time, id, string);
	pthread_mutex_unlock(&rules->m_finish);
	pthread_mutex_unlock(&rules->m_print);
}

long	ft_atoi_l(const char *str)
{
	long int	sum;
	int			i;
	int			sign;

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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

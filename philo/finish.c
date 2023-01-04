/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:59 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 13:23:19 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void finish(t_rules *rules)
{
	int i;

	i = 0;
	while (i < rules->num_philosophers)
	{
		pthread_mutex_destroy(&rules->m_forks[i]);
		// pthread_mutex_destroy(&philo[i].m_philo);
		i++;
	}
	pthread_mutex_destroy(&rules->m_print);
	pthread_mutex_destroy(&rules->m_check);
	pthread_mutex_destroy(&rules->m_finish);

	free(rules->m_forks);
}

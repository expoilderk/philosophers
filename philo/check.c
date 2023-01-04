/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:12:32 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 10:31:36 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(char **argv, int i, int j)
{
	long int	value;
	int			flag;

	flag = 1;
	while (argv[++i])
	{
		j = 0;
		value = ft_atoi_l(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			flag = 0;
		if (ft_issign(argv[i][j]) && argv[i][j + 1] != '\0')
		{
			flag = 0;
			j++;
		}
		while (argv[i][j] && ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] != '\0' && !ft_isdigit(argv[i][j]))
			flag = 0;
	}
	if (!flag)
		error_msg();
	return (flag);
}

void	error_msg(void)
{
	printf("Invalid Arguments!\n");
}

void	help_msg(void)
{
	printf("Usage: ./philo <num_of_philo> <time_to_die> <time_to_eat> \
<time_to_sleep> [num_times_philo_should_sleep]\n");
}

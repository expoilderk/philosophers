/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:11:26 by mreis-me          #+#    #+#             */
/*   Updated: 2023/01/04 11:13:25 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
	{
		help_msg();
		return (0);
	}
	if (!check(argv, 0, 0))
		return (0);
	init(argv, &rules);
	finish(&rules);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:37:29 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/09 13:18:57 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_argv(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	if (argc != 5 || argc != 6)
		return (EXIT_FAILURE);
	while (i < argc)
	{
		i++;
		num = ft_atoi(argv[i]);
		if (num <= 0  || num > INT_MAX)
			return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = NULL;
	if (ft_check_argv(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_init(argc, argv, &info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_loop(&info) == EXIT_FAILURE)
	{
		ft_free(&info);
		return(EXIT_FAILURE);
	}
	ft_free(&info);
	return (EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:37:29 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/14 13:43:37 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

static int	ft_check_argv(int argc, char **argv)
{
	int		i;
	int	num;

	i = 1;
	if (argc != 5 || argc == 6)
		return (false);
	while (i < argc)
	{
		i++;
		num = ft_atoi(argv[i]);
		if (num <= 0  || num > INT_MAX)
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = NULL;
	if (ft_check_argv(argc, argv))
		return (EXIT_FAILURE);
	if (ft_init(argc, argv, &info))
		return (EXIT_FAILURE);
	if (ft_loop(argv, &info))
	{
		ft_free(&info);
		return(EXIT_FAILURE);
	}
	ft_free(&info);
	return (EXIT_SUCCESS);
}
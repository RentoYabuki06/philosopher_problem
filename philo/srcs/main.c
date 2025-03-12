/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:37:29 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/12 13:58:08 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static int	ft_check_argv(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	if (argc != 5 || argc == 6)
		return (false);
	while (i < argc)
	{
		i++;
		num = ft_atol(argv[i]);
		if (num == 0 && !ft_strncmp(argv[1], "0\0", 2))
			return (false);
		if (num < 0  || num > INT_MAX)
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	if (ft_check_argv(argc, argv))
		return (EXIT_FAILURE);
	if (ft_init(argc, argv, &philo))
		return (EXIT_FAILURE);
	if (ft_loop(argv, &philo))
	{
		ft_free(&philo);
		return(EXIT_FAILURE);
	}
	ft_free(&philo);
	return (EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:37:29 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/21 22:35:39 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_argv(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	if (ft_atoi(argv[1]) == 1)
	{
		printf("1 1 has taken a fork\n");
		usleep(ft_atoi(argv[2]) * 1000);
		printf("1 %s died\n", argv[2]);
		return (EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_isdigit(argv[i][0]) == false)
			return (EXIT_FAILURE);
		if (ft_atoi(argv[i]) <= 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int			i;
	t_info		*info;
	t_philo		*philos;
	pthread_t	monitor;

	info = malloc(sizeof(t_info));
	if (info == NULL || ft_check_argv(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_init_info(argc, argv, info) == EXIT_FAILURE)
		return (free(info), EXIT_FAILURE);
	if (ft_init_philos(&philos, info) == EXIT_FAILURE)
		return (ft_free_all(&info, &philos), EXIT_FAILURE);
	if (pthread_create(&monitor, NULL, ft_monitor_routine, philos) != 0)
		return (ft_free_all(&info, &philos), EXIT_FAILURE);
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			printf("Failed to detach thread %d\n", i + 1);
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
		return (ft_free_all(&info, &philos), EXIT_FAILURE);
	ft_free_all(&info, &philos);
	return (ft_free_all(&info, &philos), EXIT_SUCCESS);
}

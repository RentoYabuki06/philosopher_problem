/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:04:37 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/20 21:49:53 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_init_mutex(t_info *info)
{
	int	i;

	(info)->forks = malloc(sizeof(pthread_mutex_t) * (info)->num_philo);
	if (!(info)->forks)
		return (EXIT_FAILURE);
	i = 0;
	while (i < (info)->num_philo)
	{
		if (pthread_mutex_init(&(info)->forks[i], NULL) != 0)
		{
			while (--i > 0)
				pthread_mutex_destroy(&(info)->forks[i]);
			free(info->forks);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_mutex_init(&(info)->print_mutex, NULL) != 0)
	{
		ft_free_forks(info);
		free(info->forks);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool	ft_init_philos(t_philo **philos, t_info *info)
{
	int			i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * (info)->num_philo);
	if ((*philos) == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < (info)->num_philo)
	{
		(*philos)[i].info = info;
		(*philos)[i].count_eat = 0;
		(*philos)[i].last_eat_time = info->time_start;
		(*philos)[i].index = i + 1;
		if (pthread_create(&(*philos)[i].thread, NULL, ft_philo_routine, &(*philos)[i]) != 0) {
			printf("Failed to create thread %d\n", i + 1);
			while (--i > 0)
				pthread_detach((*philos)[i].thread);
			free(*philos);
			*philos = NULL;
			ft_free_all(info, NULL);
			return (EXIT_FAILURE);
		}	
		i++;
	}
	return (EXIT_SUCCESS);
}

bool	ft_init_info(int argc, char **argv, t_info *info)
{
	(info)->flag_finish = false;
	(info)->time_start = get_current_time();
	(info)->num_philo = ft_atoi(argv[1]);
	(info)->time_to_die = ft_atoi(argv[2]);
	(info)->time_to_eat = ft_atoi(argv[3]);
	(info)->time_to_sleep = ft_atoi(argv[4]);
	(info)->must_eat_times = -1;
	if (argc == 6)
		(info)->must_eat_times = ft_atoi(argv[5]);
	if (ft_init_mutex(info) == EXIT_FAILURE)
		return (ft_free_info_without_forks(info), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:04:37 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/09 13:17:44 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_init_mutex(t_info **info)
{
	int	i;

	(*info)->forks = (pthread_t)malloc(sizeof(pthread_t) * (*info)->num_philo);
	if (!(*info)->forks)
		return (EXIT_FAILURE);
	i = 0;
	while (i < (*info)->num_philo)
	{
		if (pthread_mutex_init(&(*info)->forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&(*info)->eat_mutex, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(*info)->died_mutex, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(*info)->print_mutex, NULL) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static bool	ft_init_philo(t_info **info)
{
	int	i;

	(*info)->philo = (t_philo *)malloc(sizeof(t_philo) * (*info)->num_philo);
	if (((*info)->philo) == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < (*info)->num_philo)
	{
		(*info)->philo[i].left = EXIT_FAILURE;
		(*info)->philo[i].right = EXIT_FAILURE;
		(*info)->philo[i].is_death = EXIT_FAILURE;
		(*info)->philo[i].count_eat = 0;
		(*info)->philo[i].last_time_eating = 0;
		(*info)->philo[i].index = i + 1;
		i++;
	}
	return (EXIT_SUCCESS);
}

bool	ft_init(int argc, char **argv, t_info	**info)
{
	(*info)->num_philo = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atoi(argv[2]);
	(*info)->time_to_eat = ft_atoi(argv[3]);
	(*info)->time_to_sleep = ft_atoi(argv[4]);
	(*info)->must_eat_times = -1;
	if (argc == 6)
		(*info)->must_eat_times = ft_atoi(argv[5]);
	if (ft_init_mutex(info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_init_philo(info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

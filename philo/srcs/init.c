/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:04:37 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/12 22:10:13 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static bool	ft_init_mutex(t_info **info)
{
	int	i;

	(*info)->forks = (pthread_t)malloc(sizeof(pthread_t) * (*info)->num_philo);
	if (!(*info)->forks)
		return (false);
	i = 0;
	while (i < (*info)->num_philo)
	{
		if (pthread_mutex_init(&(*info)->forks[i], NULL) != 0)
			return (false);
		i++;
	}
	if (pthread_mutex_init(&(*info)->eat_mutex, NULL))
		return (false);
	if (pthread_mutex_init(&(*info)->died_mutex, NULL))
		return (false);
	if (pthread_mutex_init(&(*info)->print_mutex, NULL))
		return (false);
	return (true);
}

static bool	ft_init_philo(t_info **info)
{
	int	i;

	(*info)->philo = (t_philo *)malloc(sizeof(t_philo) * (*info)->num_philo);
	if (!((*info)->philo))
		return (false);
	i = 0;
	while (i < (*info)->num_philo)
	{
		(*info)->philo[i].left = false;
		(*info)->philo[i].right = false;
		(*info)->philo[i].count_eat = 0;
		(*info)->philo[i].last_time_eating = 0;
		(*info)->philo[i].index = i + 1;
		(*info)->philo[i].info = info;
	}
	return (true);
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
	if (!ft_init_mutex(info))
		return (false);
	if (!ft_init_philo(info))
		return (false);
	return (true);
}

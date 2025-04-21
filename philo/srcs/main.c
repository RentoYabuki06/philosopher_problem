/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:37:29 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/21 21:58:13 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_argv(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
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

static void	ft_take_fork_and_eating(t_philo *philo)
{
	int				right_fork;
	pthread_mutex_t	*forks;

	forks = philo->info->forks;
	right_fork = philo->index;
	if (philo->index == philo->info->num_philo)
		right_fork = 0;
	pthread_mutex_lock(&forks[right_fork]);
	ft_print_status(philo->info, "take", right_fork);
	pthread_mutex_lock(&forks[philo->index - 1]);
	ft_print_status(philo->info, "take", philo->index);
	ft_print_status(philo->info, "eat", philo->index);
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->count_eat++;
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&philo->info->eat_mutex);
	if (get_finish(philo->info) == true)
	{
		pthread_mutex_unlock(&forks[right_fork]);
		pthread_mutex_unlock(&forks[philo->index - 1]);
		return ;
	}
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(&forks[right_fork]);
	pthread_mutex_unlock(&forks[philo->index - 1]);
}

void	*pr(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 0)
		usleep(1000);
	while (get_finish(philo->info) == false)
	{
		ft_take_fork_and_eating(philo);
		if (get_finish(philo->info) == true)
			break ;
		ft_print_status(philo->info, "sleep", philo->index);
		usleep(philo->info->time_to_sleep * 1000);
		ft_print_status(philo->info, "think", philo->index);
	}
	return (NULL);
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

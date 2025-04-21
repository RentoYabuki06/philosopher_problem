/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:37:29 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/21 22:18:04 by ryabuki          ###   ########.fr       */
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
	int				left_fork;
	int				right_fork;
	int				first;
	int				second;
	pthread_mutex_t	*forks;

	forks = philo->info->forks;

	// 左右のフォークのインデックスを決定
	left_fork = philo->index - 1;
	right_fork = (philo->index == philo->info->num_philo) ? 0 : philo->index;

	// フォークの番号の小さい方を先にロック
	if (left_fork < right_fork)
	{
		first = left_fork;
		second = right_fork;
	}
	else
	{
		first = right_fork;
		second = left_fork;
	}

	pthread_mutex_lock(&forks[first]);
	ft_print_status(philo->info, "take", first + 1);
	pthread_mutex_lock(&forks[second]);
	ft_print_status(philo->info, "take", second + 1);

	ft_print_status(philo->info, "eat", philo->index);
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->count_eat++;
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&philo->info->eat_mutex);

	if (get_finish(philo->info) == true)
	{
		pthread_mutex_unlock(&forks[second]);
		pthread_mutex_unlock(&forks[first]);
		return;
	}

	usleep(philo->info->time_to_eat * 1000);

	pthread_mutex_unlock(&forks[second]);
	pthread_mutex_unlock(&forks[first]);
}

unsigned int	my_rand(unsigned int *seed)
{
	*seed = (1103515245 * (*seed) + 12345) & 0x7fffffff;
	return *seed;
}

void	*pr(void *arg)
{
	t_philo	*philo;
	unsigned int seed;
	int delay;

	philo = (t_philo *)arg;
	ft_print_status(philo->info, "think", philo->index);
	// 各スレッドに一意なseed（indexや時刻などを使って）
	seed = (unsigned int)(philo->index * 1234 + (uintptr_t)philo);

	// 擬似乱数で遅延時間を決定（0〜199 ms）
	delay = my_rand(&seed) % 200;
	usleep(delay * 100);

	while (get_finish(philo->info) == false)
	{
		ft_take_fork_and_eating(philo);
		if (get_finish(philo->info) == true)
			break;
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

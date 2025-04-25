/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:31:43 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/25 15:07:50 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_decide_forks(t_philo *philo, int *first, int *second)
{
	int				left_fork;
	int				right_fork;

	left_fork = philo->index - 1;
	right_fork = philo->index;
	*first = left_fork;
	*second = right_fork;
	if (philo->index == philo->info->num_philo)
	{
		*first = left_fork;
		*second = 0;
	}
}

// static void	ft_take_fork(t_info *info, int first, int second)
// {
// 	while (true)
// 	{
// 		pthread_mutex_lock(&info->fork_mutex);
// 		if (info->fork_available[first] && info->fork_available[second])
// 		{
// 			info->fork_available[first] = false;
// 			info->fork_available[second] = false;
// 			pthread_mutex_unlock(&info->fork_mutex);
// 			return ;
// 		}
// 		else
// 		{
// 			pthread_mutex_unlock(&info->fork_mutex);
// 		}
// 		usleep(100);
// 	}
// }

static void	ft_return_fork(t_info *info, int first, int second)
{
	// pthread_mutex_lock(&info->fork_mutex);
	// info->fork_available[first] = true;
	// info->fork_available[second] = true;
	// pthread_mutex_unlock(&info->fork_mutex);
	pthread_mutex_unlock(&info->forks[second]);
	pthread_mutex_unlock(&info->forks[first]);
}

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->last_eat_time = get_current_time();
	philo->count_eat++;
	pthread_mutex_unlock(&philo->info->eat_mutex);
	ft_print_status(philo->info, "eat", philo->index);
}

void	ft_take_fork_and_eating(t_philo *philo)
{
	int				first;
	int				second;
	pthread_mutex_t	*forks;

	forks = philo->info->forks;
	ft_decide_forks(philo, &first, &second);
	// ft_take_fork(philo->info, first, second);
	pthread_mutex_lock(&forks[first]);
	ft_print_status(philo->info, "take", first + 1);
	pthread_mutex_lock(&forks[second]);
	ft_print_status(philo->info, "take", second + 1);
	ft_eat(philo);
	if (get_finish(philo->info) == true)
	{
		ft_return_fork(philo->info, first, second);
		return ;
	}
	usleep(philo->info->time_to_eat * 1000);
	ft_return_fork(philo->info, first, second);
}

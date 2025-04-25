/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:31:43 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/25 15:12:47 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_decide_forks(t_philo *philo, int *first, int *second)
{
	int				left_fork;
	int				right_fork;

	left_fork = philo->index - 1;
	right_fork = philo->index;
	if (philo->index == philo->info->num_philo)
	{
		right_fork = 0;
	}
	if (left_fork < right_fork)
	{
		*first = left_fork;
		*second = right_fork;
	}
	else
	{
		*first = right_fork;
		*second = left_fork;
	}
}

static void	ft_return_fork(t_info *info, int first, int second)
{
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

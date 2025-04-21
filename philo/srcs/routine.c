/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:27:55 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/21 22:28:55 by ryabuki          ###   ########.fr       */
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
		right_fork = 0;
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

static void	ft_take_fork_and_eating(t_philo *philo)
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
	ft_print_status(philo->info, "eat", philo->index);
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->count_eat++;
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&philo->info->eat_mutex);
	if (get_finish(philo->info) == true)
	{
		pthread_mutex_unlock(&forks[second]);
		pthread_mutex_unlock(&forks[first]);
		return ;
	}
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(&forks[second]);
	pthread_mutex_unlock(&forks[first]);
}

unsigned int	my_rand(unsigned int *seed)
{
	*seed = (1103515245 * (*seed) + 12345) & 0x7fffffff;
	return (*seed);
}

void	*pr(void *arg)
{
	t_philo			*philo;
	unsigned int	seed;
	int				delay;

	philo = (t_philo *)arg;
	ft_print_status(philo->info, "think", philo->index);
	seed = (unsigned int)(philo->index * 1234 + (uintptr_t)philo);
	delay = my_rand(&seed) % 200;
	usleep(delay * 100);
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

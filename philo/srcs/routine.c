/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:27:55 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/25 18:09:48 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	my_rand(unsigned int *seed)
{
	*seed = (1103515245 * (*seed) + 12345) & 0x7fffffff;
	return (*seed);
}

static void	ft_initial_wait(t_philo *philo)
{
	// unsigned int	seed;
	// int				delay_base;
	// int				random_offset;

	// seed = (unsigned int)(philo->index * 1234 + (uintptr_t)philo);
	// delay_base = philo->index * 1000;
	// random_offset = my_rand(&seed) % 1000;
	if (philo->info->num_philo % 2 == 0)
	{
		if (philo->index % 2 == 0)
		{
			usleep(2000);
		}
		else
		{
			usleep(0);
		}
	}
	else if (philo->info->num_philo > 10)
	{
		usleep(philo->index * 100);
	}
	else
	{
		usleep(philo->index * 1000);
	}
	// if (philo->index % 2 == 1)
	// 	delay_base += 3000;
	// usleep((delay_base + random_offset) * 10);
}

void	*pr(void *arg)
{
	t_philo			*philo;
	int				think_time;

	philo = (t_philo *)arg;
	ft_print_status(philo->info, "think", philo->index);
	ft_initial_wait(philo);
	while (get_finish(philo->info) == false)
	{
		ft_take_fork_and_eating(philo);
		if (get_finish(philo->info) == true)
			break ;
		ft_print_status(philo->info, "sleep", philo->index);
		usleep((philo->info->time_to_sleep) * 1000);
		ft_print_status(philo->info, "think", philo->index);
		think_time = philo->info->time_to_eat - philo->info->time_to_sleep;
		if (think_time > 0)
			usleep((think_time + 1) * 1000);
	}
	return (NULL);
}

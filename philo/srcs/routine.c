/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:27:55 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/25 18:35:28 by ryabuki          ###   ########.fr       */
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
	if (philo->info->num_philo % 2 == 0)
	{
		if (philo->index % 2 == 0)
			usleep(2000);
	}
	else 
		usleep(philo->index * 200);
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
		if (think_time >= 0)
			usleep((think_time + 1) * 1000);
	}
	return (NULL);
}

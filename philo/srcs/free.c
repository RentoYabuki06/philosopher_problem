/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:02:40 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/22 12:54:50 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_forks(t_info *info)
{
	int	i;

	if (info == NULL || info->forks == NULL)
		return ;
	i = 0;
	while (i < (info)->num_philo)
	{
		pthread_mutex_destroy(&(info)->forks[i]);
		i++;
	}
	free(info->forks);
	info->forks = NULL;
}

void	ft_free_info_without_forks(t_info *info)
{
	if (info == NULL)
		return ;
	pthread_mutex_destroy(&(info)->print_mutex);
	pthread_mutex_destroy(&(info)->died_mutex);
	pthread_mutex_destroy(&(info)->eat_mutex);
	pthread_mutex_destroy(&(info)->fork_mutex);
	if (info->fork_available)
		free(info->fork_available);
	free(info);
}

void	ft_free_all(t_info **info_ptr, t_philo **philos_ptr)
{
	if (info_ptr && *info_ptr)
	{
		ft_free_forks(*info_ptr);
		ft_free_info_without_forks(*info_ptr);
		*info_ptr = NULL;
	}
	if (philos_ptr && *philos_ptr)
	{
		free(*philos_ptr);
		*philos_ptr = NULL;
	}
}

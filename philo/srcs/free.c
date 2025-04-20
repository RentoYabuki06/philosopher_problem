/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:02:40 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/20 21:37:14 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_forks(t_info *info)
{
	int 	i;

	if (info == NULL)
		return ;
	i = 0;
	while (i < (info)->num_philo)
	{
		pthread_mutex_destroy(&(info)->forks[i]);
		i++;
	}
}

void	ft_free_info_without_forks(t_info *info)
{
	if (info == NULL)
		return ;
	pthread_mutex_destroy(&(info)->print_mutex);
	free(info);
}


void	ft_free_all(t_info *info, t_philo **philos)
{
	if (info == NULL)
		return ;
	ft_free_forks(info);
	ft_free_info_without_forks(info);
	if (*philos)
		free(*philos);
	philos = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:02:40 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/20 19:59:14 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_info *info, t_philo **philos)
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
	pthread_mutex_destroy(&(info)->eat_mutex);
	pthread_mutex_destroy(&(info)->died_mutex);
	pthread_mutex_destroy(&(info)->print_mutex);
	free(*philos);
	philos = NULL;
	free(info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:40:22 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/09 13:40:34 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_thread_create(t_info **info)
{
	int	i;

	i = 0;
	while (i < (*info)->num_philo)
	{
		pthread_create(&((*info)->philo[i].thread), NULL, ft_action((*info)->philo[i]), NULL);
		i++;
	}
}

void	ft_philo_thread_join(t_info **info)
{
	int	i;

	i = 0;
	while (i < (*info)->num_philo)
	{
		pthread_join((*info)->philo[i].thread, NULL);
		i++;
	}
}

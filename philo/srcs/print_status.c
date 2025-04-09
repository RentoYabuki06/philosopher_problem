/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:03:39 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/09 13:34:50 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_info **info, char *act, int time, int index_philo)
{
	pthread_mutex_lock(&(*info)->print_mutex);
	pthread_mutex_lock(&(*info)->died_mutex);
	if (ft_strncmp(act, "take\0", 5) == 0)
		printf("%d %d has taken a fork\n", time, index_philo);
	if (ft_strncmp(act, "eat\0", 4) == 0)
		printf("%d %d is eating\n", time, index_philo);
	if (ft_strncmp(act, "sleep\0", 6) == 0)
		printf("%d %d is sleeping\n", time, index_philo);
	if (ft_strncmp(act, "think\0", 6) == 0)
		printf("%d %d is thinking\n", time, index_philo);
	if (ft_strncmp(act, "die\0", 4) == 0)
		printf("%d %d died\n", time, index_philo);
	pthread_mutex_unlock(&(*info)->print_mutex);
	pthread_mutex_unlock(&(*info)->died_mutex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:03:39 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/20 19:40:59 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_info *info, char *act, int index_philo)
{
	long long	now_time;

	pthread_mutex_lock(&(info)->print_mutex);
	now_time = get_current_time() - info->time_start;
	if (ft_strncmp(act, "take\0", 5) == 0)
		printf("%lld %d has taken a fork\n", now_time, index_philo);
	if (ft_strncmp(act, "eat\0", 4) == 0)
		printf("%lld %d is eating\n", now_time, index_philo);
	if (ft_strncmp(act, "sleep\0", 6) == 0)
		printf("%lld %d is sleeping\n", now_time, index_philo);
	if (ft_strncmp(act, "think\0", 6) == 0)
		printf("%lld %d is thinking\n", now_time, index_philo);
	if (ft_strncmp(act, "die\0", 4) == 0)
		printf("%lld %d died\n", now_time, index_philo);
	pthread_mutex_unlock(&(info)->print_mutex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:11:11 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/20 20:00:35 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor_routine(void *arg)
{
	int			i;
	t_info		*info;
	t_philo		*philos;

	philos = (t_philo *)arg;
	info = philos[0].info;
	while (info->flag_finish == false)
	{
		i = 0;
		while (i < info->num_philo)
		{
			if (get_current_time() - philos[i].last_eat_time > info->time_to_die)
			{
				ft_print_status(info, "die", philos[i].index);
				info->flag_finish = 1;
			}
			i++;
		}
		if (info->must_eat_times > 0)
		{
			bool done = true;
			i = 0;
			while (i < info->num_philo)
			{
				if (philos[i].count_eat < info->must_eat_times)
				{
					done = false;
					break;
				}
				i++;
			}
			if (done == true)
			{
				pthread_mutex_lock(&info->print_mutex);
				info->flag_finish = true;
				return (NULL);
			}
		}
		usleep(1000);
	}
	return (NULL);
}

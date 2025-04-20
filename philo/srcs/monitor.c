/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:11:11 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/20 21:05:45 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_is_died(int i, t_philo *philos, t_info *info)
{
	long long time_to_die;

	time_to_die = info->time_to_die * 1000;
	if(get_current_time() - philos[i].last_eat_time > time_to_die)
		return (true);
	return (false);
}

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
			if (ft_is_died(i, philos, info) == true)
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
				printf("all philosopher is eated!!");
				pthread_mutex_lock(&info->print_mutex);
				info->flag_finish = true;
				return (NULL);
			}
		}
		usleep(1000);
	}
	return (NULL);
}

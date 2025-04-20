/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:11:11 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/20 23:11:49 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_is_died(int i, t_philo *philos, t_info *info)
{
	long long time_to_die;

	time_to_die = info->time_to_die;
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
	while (get_finish(info) == false)
	{
		i = 0;
		while (i < info->num_philo)
		{
			pthread_mutex_lock(&info->eat_mutex);
			bool is_dead = ft_is_died(i, philos, info);
			pthread_mutex_unlock(&info->eat_mutex);
			// printf("[%d] is checkd\n", i);
			if (is_dead == true)
			{
				ft_print_status(info, "die", philos[i].index);
				set_finish(info, true);
				return (NULL) ;
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
				set_finish(info, true);
				return (NULL);
			}
		}
		usleep(1000);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:11:11 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/25 15:05:48 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_is_died(int i, t_philo *philos, t_info *info)
{
	long long	time_to_die;

	time_to_die = info->time_to_die;
	if (get_current_time() - philos[i].last_eat_time > time_to_die)
		return (true);
	return (false);
}

static bool	ft_check_death(t_info *info, t_philo *philos)
{
	int		i;
	bool	is_dead;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_lock(&info->eat_mutex);
		is_dead = ft_is_died(i, philos, info);
		pthread_mutex_unlock(&info->eat_mutex);
		if (is_dead == true)
		{
			ft_print_status(info, "die", philos[i].index);
			set_finish(info, true);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	ft_check_all_eat(t_info *info, t_philo *philos)
{
	int		i;
	int		count_eat;
	bool	done;

	done = true;
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_lock(&info->eat_mutex);
		count_eat = philos[i].count_eat;
		pthread_mutex_unlock(&info->eat_mutex);
		if (count_eat < info->must_eat_times)
		{
			done = false;
			break ;
		}
		i++;
	}
	if (done == true)
	{
		set_finish(info, true);
		return (true);
	}
	return (false);
}

void	*ft_monitor_routine(void *arg)
{
	t_info		*info;
	t_philo		*philos;

	philos = (t_philo *)arg;
	info = philos[0].info;
	while (get_finish(info) == false)
	{
		if (ft_check_death(info, philos) == true)
			return (NULL);
		if (info->must_eat_times > 0)
		{
			if (ft_check_all_eat(info, philos) == true)
				return (NULL);
		}
		usleep(10);
	}
	return (NULL);
}

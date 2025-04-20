/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:19:36 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/20 22:21:46 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_finish(t_info *info)
{
	bool	flag;

	pthread_mutex_lock(&info->died_mutex);
	flag = info->flag_finish;
	pthread_mutex_unlock(&info->died_mutex);
	return (flag);
}

void	set_finish(t_info *info, bool value)
{
	pthread_mutex_lock(&info->died_mutex);
	info->flag_finish = value;
	pthread_mutex_unlock(&info->died_mutex);
}

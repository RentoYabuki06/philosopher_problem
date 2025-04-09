/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alldied.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:44:22 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/09 12:12:46 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	*ft_check_alldied(t_info *info)
{
	int	i;

	i = 0;
	if (!info)
		return (NULL);
	while (++i <info->num_philo)
	{
		if (info->philo[i].is_death)
			return (false);
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alldied.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:44:22 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/12 13:46:45 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

bool	*ft_check_alldied(t_philo *philo)
{
	if (!philo)
		return (NULL);
	while (philo)
	{
		if (philo->is_death)
			return (false);
		if (philo->next)
			philo = philo->next;
	}
	return (true);
}

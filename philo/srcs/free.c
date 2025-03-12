/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:02:40 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/12 12:04:42 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	ft_free(t_philo **philo)
{
	t_philo	*current;
	t_philo	*next;

	if (!philo || !*philo)
		return ;
	current = *philo;
	while (current->next)
	{
		next = current->next;
		free (current);
		current = next;
	}
	free(current);
	free(philo);
}

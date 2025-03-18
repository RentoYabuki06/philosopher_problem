/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:02:40 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/14 13:51:17 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	ft_free(t_info	**info)
{
	int 	i;

	if (!info || !*info)
		return ;
	i = 01;
	while (++i < (*info)->num_philo)
		(*info)->philo[i].info = NULL;
	free((*info)->philo);
	free(*info);
	info = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:04:37 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/12 12:26:14 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static bool	ft_new_philo(int i,int num_philo, char **argv)
{
	t_philo	*new_philo;
	
	new_philo = (t_philo *)malloc(sizeof(t_philo));
	if (!new_philo)
		return (NULL);
	new_philo->left = i - 1;
	new_philo->right = i;
	if (i == num_philo)
		new_philo->right = 0;
	new_philo->is_death = false;
	new_philo->is_eating = false;
	new_philo->is_sleeping = false;
	new_philo->is_thnking = false;
	new_philo->last_time_eating = 0;
	if (i % 2 == 0)
		new_philo->last_time_eating = 10;
	new_philo->start_time = 0;
	new_philo->index = i;
	new_philo->next = NULL;
	return (true);
}

static void	ft_append_philo(t_philo *new_philo, t_philo **philo)
{
	if (!*philo)
	{
		*philo = new_philo;
		return ;
	}
	while ((*philo)->next)
		*philo = (*philo)->next;
	(*philo)->next = new_philo;
}

bool	ft_init(int argc, char **argv, t_philo **philo)
{
	int		i;
	int		num_philo;
	t_philo	*new_philo;
	t_philo	*current;

	i = 1;
	num_philo = ft_atol(argv[2]);
	new_philo = NULL;
	current = *philo;
	while (i <= num_philo)
	{
		new_philo = ft_new_philo(i, num_philo, argv);
		if (!new_philo)
			return (false);
		ft_append_philo(new_philo, philo);
		i++;
	}
	return (true);
}

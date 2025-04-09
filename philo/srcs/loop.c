/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:58:16 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/09 13:44:10 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_take_spoon(char *side, t_philo **philo, int index, int time)
{
	// スプーンとphiloの情報どちらもlockして書き換えてからアンロック
	pthread_mutex_lock(fork);
	if (ft_strncmp(side, "left\0", 5) == 0)
	{
		(*philo)->left = true;
		*spoon << index - 1; //スプーンを取った処理を書きたい
		ft_print("take", now_time, index);
	}
	if (ft_strncmp(side, "right\0", 5) == 0)
	{
		(*philo)->right = true;
		*spoon << index; //スプーンを取った処理を書きたい
		ft_print("take", now_time, index);
	}
	pthread_mutex_unlock();
	printf("%d %d has taken a fork\n", time, (*philo)->index);
}

static void	ft_eat(t_philo **philo, int time)
{
	//
}

static void	ft_sleep(t_philo **philo, int time)
{
	ft_print_status();
}

static void ft_think(t_philo **philo)
{
	printf("%d %d is thinking\n", time, (*philo)->index);
}

static void	ft_die(t_philo **philo)
{
	printf("%d %d died\n", time, (*philo)->index);
}

// indexとかbit処理がずれている前提なので後で修正
void	*ft_action(t_philo *philo, int *spoon)
{
	int	index_philo;

	index_philo = philo->index;
	if (!philo->left && !(*spoon << index_philo - 1))
		ft_take_spoon();
	usleep(10);
	if (!philo->right && !(*spoon << index_philo))
	{
		pthread_mutex_lock();
		pthread_mutex_lock();
		philo->right = true;
		*spoon << index_philo;
		pthread_mutex_unlock();
		pthread_mutex_unlock();
	}
	if (philo->right && philo->left)
		ft_eat();
}

void	*ft_monitor(t_info **info)
{
	
}

bool	ft_loop(t_info **info)
{
	pthread_t	thread_monitor;

	(*info)->time_start = get_current_time();
	ft_philo_thread_create(info);
	ft_philo_thread_join(info);
	pthread_create(&thread_monitor, NULL, ft_monitor, (void *)info);
	pthread_join(thread_monitor, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:58:16 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/14 14:07:56 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

static void	ft_take_spoon(char *side, t_philo **philo, int index)
{
	// スプーンとphiloの情報どちらもlockして書き換えてからアンロック
	pthread_mutex_lock();
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
}

static void	ft_eat(t_philo **philo)
{
	int spentime;

	spentime = 0;
	pthread_mutex_lock();
	ft_print("eat", now_time, (*philo)->index);
	while ((*philo)->start_time - now_time > 0)
	{
		now_time++; //時間が過ぎるまで
	}
	(*philo)->is_eating = false;
	(*philo)->last_time_eating = now_time;
	pthread_mutex_unlock();
	ft_sleep(philo);
}

static void	ft_sleep(t_philo **philo)
{

	(*philo)->is_sleeping = true;
	ft_print("sleep", now_time, (*philo)->index);
	(*philo)->is_sleeping = false;
	ft_think();
}

static void ft_think(t_philo **philo)
{
	(*philo)->is_sleeping = true;
	ft_print("sleep", now_time, (*philo)->index);
	(*philo)->is_sleeping = false;
	if (now_time - (*philo)->last_time_eating < time_to_die)
		ft_die();
	
}

static void	ft_die(t_philo **philo)
{
	ft_print("die", now_time, (*philo)->index);
	(*philo)->is_death = true;
}

// indexとかbit処理がずれている前提なので後で修正
static void	*ft_action(t_philo *philo, int *spoon)
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

static long long get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec / 1000 + tv.tv_sec * 1000)
}

bool	ft_loop(t_info **info)
{
	(*info)->time_start = get_current_time();
	if (create)
}
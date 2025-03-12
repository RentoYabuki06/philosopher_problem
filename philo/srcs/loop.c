/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:58:16 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/12 14:25:42 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static void	ft_print(char *act, int time, int index_philo)
{
	// 1つずつスレッドより書き出していくイメージ
	pthread_mutex_lock();
	if (ft_strncmp(act, "take\0", 5) == 0)
		printf("%d %d has taken a fork\n",time, index_philo);
	if (ft_strncmp(act, "eat\0", 4) == 0)
		printf("%d %d is eating\n",time, index_philo);
	if (ft_strncmp(act, "sleep\0", 6) == 0)
		printf("%d %d is sleeping\n",time, index_philo);
	if (ft_strncmp(act, "think\0", 6) == 0)
		printf("%d %d is thinking\n",time, index_philo);
	if (ft_strncmp(act, "die\0", 4) == 0)
		printf("%d %d died\n",time, index_philo);
	pthread_mutex_unlock();
}

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

bool	ft_loop(char **argv, t_philo **philo)
{
	t_philo					**top_philo;
	pthread_t				*thread;
	const pthread_attr_t	**attr;
	void					*arg;

	top_philo = philo;
	while (*philo)
	{
		if (pthread_create(thread, attr , ft_action(*philo), arg) == 0)
			return (false);
		if ((*philo)->next)
			return (true);
		*philo = (*philo)->next;
	}
	while (*top_philo)
	{
		pthread_detach(thread);
	}
}
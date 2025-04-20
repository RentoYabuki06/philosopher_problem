/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:30:36 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/20 21:37:14 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <stddef.h>

typedef struct	s_info	t_info;
typedef struct	s_philo	t_philo;

struct	s_info
{
	bool			flag_finish;
	int 			num_philo;
	long long 		time_start;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
};

struct	s_philo
{
	int				count_eat;
	long long 		last_eat_time;
	int				index;
	pthread_t		thread;
	t_info			*info;
};

void	*ft_monitor_routine(void *arg);
void	*ft_philo_routine(void *arg);

bool	ft_init_info(int argc, char **argv, t_info *info);
bool	ft_init_philos(t_philo **philos, t_info *info);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_print_status(t_info *info, char *act, int index_philo);

long long get_current_time(void);

void	ft_free_forks(t_info *info);
void	ft_free_info_without_forks(t_info *info);
void	ft_free_all(t_info *info, t_philo **philos);

#endif
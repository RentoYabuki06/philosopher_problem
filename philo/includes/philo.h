/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:30:36 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/09 13:40:53 by ryabuki          ###   ########.fr       */
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
	int 			num_philo;
	int 			time_start;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	print_mutex;
	t_philo			*philo;
};

struct	s_philo
{
	bool			left;
	bool			right;
	bool			is_death;
	int				count_eat;
	int				last_time_eating;
	int				index;
	pthread_t		thread;
};

bool	ft_loop(t_info **info);
int		ft_atoi(const char *str);
void	ft_free_info(t_info **info);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
bool	*ft_check_alldied(t_info *philo);
bool	ft_init(int argc, char **argv, t_info **info);

void	ft_philo_thread_create(t_info **info);
void	ft_philo_thread_join(t_info **info);

void	ft_print_status(t_info **info,char *act, int index_philo);

long long get_current_time(void);

#endif
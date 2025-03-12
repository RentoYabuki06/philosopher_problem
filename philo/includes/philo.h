/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:30:36 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/12 21:46:53 by yabukirento      ###   ########.fr       */
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

typedef struct	s_info
{
	int 			num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	print_mutex;
	t_philo			*philo;
}				t_info;

typedef struct	s_philo
{
	bool			left;
	bool			right;
	int				count_eat;
	int				last_time_eating;
	int				index;
	t_info			*info;
}				t_philo;

bool	ft_loop(char **argv, t_philo **philo);
long	ft_atol(const char *s);
void	ft_free(t_philo **philo);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
bool	*ft_check_alldied(t_philo *philo);
bool	ft_init(int argc, char **argv, t_philo **philo);
t_philo	*ft_find_last(t_philo *philo);
void	ft_print_status(t_info **info,char *act, int index_philo);

#endif
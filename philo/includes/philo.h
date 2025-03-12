/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:30:36 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/12 14:08:21 by yabukirento      ###   ########.fr       */
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

// typedef struct	s_spoon
// {
// 	bool	available_1;
// 	bool	available_2;
// 	bool	available_3;
// 	bool	available_4;
// 	bool	available_5;
// 	bool	available_6;
// 	bool	available_7;
// 	bool	available_8;
// }				t_spoon;

typedef struct	s_philo
{
	bool			left;
	bool			right;
	bool			is_death;
	bool			is_eating;
	bool			is_sleeping;
	bool			is_thnking;
	int				last_time_eating;
	int				start_time;
	int				index;
	struct s_philo	*next;
	
}				t_philo;

bool	ft_loop(char **argv, t_philo **philo);
long	ft_atol(const char *s);
void	ft_free(t_philo **philo);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
bool	*ft_check_alldied(t_philo *philo);
bool	ft_init(int argc, char **argv, t_philo **philo);
t_philo	*ft_find_last(t_philo *philo);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:15:04 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/14 13:44:22 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/philo.h"

static int	ft_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	ans;

	ans = 0;
	sign = 1;
	i = ft_sign(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((ans > (INT_MAX / 10))
			|| (ans == (INT_MAX / 10) && (str[i] >= '8' && str[i] <= '9')))
			return (false);
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	return ((int)ans * sign);
}
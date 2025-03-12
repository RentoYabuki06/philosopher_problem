/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:21:15 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/12 12:03:32 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	if (n == 0)
		return (0);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (ps1 == NULL && ps2 == NULL)
		return (0);
	while (*ps1 != '\0' && *ps2 != '\0' && i < n)
	{
		if (*ps1 != *ps2)
		{
			return (*ps1 - *ps2);
		}
		ps1++;
		ps2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*ps1 - *ps2);
}

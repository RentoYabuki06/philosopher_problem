
#include <stdio.h>
#include <limits.h>

static int	ft_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
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
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	return ((int)ans * sign);
}

int main(int argc, char **argv)
{
	long	num;
	printf("987654321 is %d\n", ft_atoi("987654321"));
	printf("-1 is %d\n", ft_atoi("-1"));
	printf("98765432101234 is %d\n", ft_atoi("98765432101234"));
	return (1);
}
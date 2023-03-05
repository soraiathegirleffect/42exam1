int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}




// orrrrrrrrrrrrrr
#include <stdio.h>

int ft_atoi(const char *str)
{
    int i;
    long int res;
    int sign;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] >= 9 && str[i] <= 13 && str[i] == 32)
        i++;
    if (str[i] == 43 || str[i] == 45)
    {
        if (str[i] == 45)
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
        res = (str[i] - 48) + (res * 10);
        i++;
    }
    return (sign * res);
}

#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr) 
{
    int n = nbr;
    int len = 0;

    if (nbr <= 0)
    {
	len++;
    }
    while (n) 
    {
        n /= 10;
        len++;
    }
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    if (result == NULL) 
    {
        return NULL;
    }
    result[len] = '\0';
    if (nbr == 0)
    {
	result[0] = '0';
	return(result);
    }
    if (nbr < 0) 
    {
        result[0] = '-';
        nbr = -nbr;
    }
    while (nbr) 
    {
        result[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return result;
}











//or mine

static int	number_digit(int nn)
{
	int	c;

	c = 0;
	if (nn == 0)
		return (1);
	if (nn < 0)
		c++;
	while (nn != 0)
	{
		nn = nn / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	long int		nb;

	nb = n;
	size = number_digit(nb);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * (-1);
	}
	if (nb == 0)
		str[0] = '0';
	str[size] = '\0';
	while (nb != 0)
	{
		str[size - 1] = (nb % 10) + 48;
		nb = nb / 10;
		size--;
	}
	return (str);
}

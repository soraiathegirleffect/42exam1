#include <stdio.h>

int             max(int* tab, unsigned int len)
{
	unsigned int	i;
	int res;

	i = 0;
	if (len == 0)
		return (0);
	res = tab[0];

	while (i < len)
	{
		if (tab[i] > res)
			res = tab[i];
		i++;
	}
	return (res);
}

/*int main(void)
{
	int	tab[] = {-42, 0, -5, -64, -2, -68, -1};
	printf("max : %d\n", max(tab, 7));
	return (0);
}*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (str[i])
			{
			if ((str[i] >= 'a' && str[i] < 'z') || (str[i] >= 'A' && str[i] < 'Z'))
				str[i] = str[i] + 1;
			else if (str[i] == 'Z' || str[i] == 'z')
				str[i] = str[i] - 25;
			write(1, &str[i], 1);
			i++;
			}
	}	
	write(1, "\n", 1);
	return(0);
}

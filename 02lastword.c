#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		i--;
		while ((av[1][i] == 32 || (av[1][i] >= 9 && av[1][i] <= 13)) && i >= 0)
			i--;
		while (av[1][i] > 32 && av[1][i] < 127)
			i--;
		i++;
		while (av[1][i] > 32 && av[1][i] < 127 && av[1][i])
		{
			write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}






// FIRST WORD WAS:

#include <unistd.h>

int main (int ac, char **av)
{
	int i;
	
	i = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

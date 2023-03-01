int		main(int argc, char **argv)
{
	if (argc == 2)
	int	j = 0;
	int i = 0;
	
	if (argc == 2)
	{
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] >= 33 && str[i + 1] <= 126)
			j = i + 1;
		i++;
	}
	while (str[j] >= 33 && str[j] <= 127)
	{
		write(1, &str[j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}



//orrrrrrrrrrrrrrrrrrrr


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

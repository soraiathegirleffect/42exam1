#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;

	if (ac == 2)
	{
		while(av[1][i])
		{
			if ((av[1][i] >= 'a' && av[1][i] <= 'm') || (av[1][i]  >= 'A' && av[1][i] <= 'M'))
				av[1][i] =  av[1][i] + 13; 
			else if((av[1][i] >= 'n' && av[1][i] <= 'z') || (av[1][i]  >= 'N' && av[1][i] <= 'Z'))
				av[1][i] =  av[1][i] - 13;
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}



//ORRRRRR




#include <unistd.h>

void rot13(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
			str[i] = str[i] + 13;
		else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
			str[i] = str[i] - 13;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		rot13(av[1]);
	write(1, "\n", 1);
	return(0)
}



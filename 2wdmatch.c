#include <unistd.h>

void ft_putstr(char const *str)
{
	int i = 0;

	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char const *argv[])
{
	int i = 0;
	int j = 0;

	if (argc == 3)
	{
		while (argv[2][j])
			if (argv[2][j++] == argv[1][i])
				i += 1;
		if (!argv[1][i])
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

// orrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.
If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.
If the number of arguments is not 2, the program displays a \n.
Examples:
$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int b;
	int check;

	i = 0;
	b = 0;
	check = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			while (av[2][b])
			{
				if (av[1][i] == av[2][b])
				{
					check++;
					b++;
					break;
				}
				b++;
			}
			i++;
		}
		i = 0;
		while (av[1][i])
			i++;
		if (check == i)
		{
			b = 0;
			while (av[1][b])
			{
				write (1, &av[1][b], 1);
				b++;
			}
		}
	}
	write (1, "\n", 1);
}

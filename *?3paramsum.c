#include <unistd.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int		main(int argc, char **argv)
{
	(void)argv;		// Silence 'unused parameter' error

	ft_putnbr(argc - 1);
	write(1, "\n", 1);

	return (0);
}

// orrrrrrrrrrrr
Write a program that displays the number of arguments passed to it, followed by
a newline.
If there are no arguments, just display a 0 followed by a newline.
Example:
$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/

#include <unistd.h>

void	ft_write(int i)
{
	char c;

	if (i > 9)
	{
		ft_write(i / 10);
		ft_write(i % 10);
	}
	else
	{
		c = i + 48;
		write (1, &c, 1);
	}
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac >= 2)
	{
		av++;
		while (av[i])
			i++;
		ft_write(i);
		write (1, "\n", 1);
	}
	else
		write (1, "0\n", 2);
}

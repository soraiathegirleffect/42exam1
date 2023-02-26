#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int b;
	int check;

	i = 0;
	b = 0;
	check = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			while (av[2][b])
			{
				if (av[1][i] == av[2][b])
				{
					check++;
					break; /* goes back behind previous while (while av[1][i] then i++ */
				}
				b++;
			}
			i++;
		}
		if (check == i)
		{
			write (1, "1", 1);
		}
		else
			write (1, "0", 1);
	}
	write (1, "\n", 1);
}

////orrrr


#include <unistd.h>

void	hidenp(char *probe, char *target)
{
	while (*probe != '\0')
	{
		while (*probe != *target && *target != '\0')
			++target;
		if (*target == '\0')
		{
			write(1, "0", 1);
			return;
		}
		++target;
		++probe;
	}
	write(1, "1", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}


/* Write a program named hidenp that takes two strings and displays 1 followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.
Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.
If the number of parameters is not 2, the program displays a newline. */

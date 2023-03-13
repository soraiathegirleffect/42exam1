#include <unistd.h>

int wordlen(char *str)
{
	int i = 0;

	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

int threespstr(char *str)
{
	int len;
	int word = 1;

	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		len = wordlen(str);
		if (len > 0 && word == 0)
			write(1, "   ", 3);
		write(1, str, len);
		word = 0;
		str = str + len;
	}
}

int main (int ac, char **av)
{
	if (ac == 2)
		threespstr(av[1]);
	
	write(1, "\n", 1);
	return (0);
}



// orrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr



#include <unistd.h>

int		word_len(char *str)
{
	int i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void	expand_str(char *str)
{
	int len;
	int first_word = 1;

	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			++str;
		len = word_len(str);
		if (len > 0 && first_word == 0)
			write(1, "   ", 3);
		first_word = 0;
		write(1, str, len);
		str = str + len;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);

	write(1, "\n", 1);
	return (0);
}


// orrrrrrrrrrrrr 
Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.
A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.
If the number of parameters is not 1, or if there are no words, simply display
a newline.
Examples:
$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			while (av[1][i] == 32 || (av[1][i] >= 9 && av[1][i] <= 13))
				i++;
			while (av[1][i] > 32 && av[1][i] < 127)
			{
				write (1, &av[1][i], 1);
				i++;
			}
			while (av[1][i] == 32 || (av[1][i] >= 9 && av[1][i] <= 13))
			{
				if (av[1][i + 1] > 32 && av[1][i + 1] < 127)
					write (1, "   ", 3);
				i++;
			}
		}
	}
	write (1, "\n", 1);
}

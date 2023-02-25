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

#include <stdlib.h>
#include <stdio.h>

int		word_counter(char *str)
{
	int i;
	int checker;
	int count;

	i = 0;
	checker = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		{
			i++;
			checker = 0;
		}
		while (str[i] > 32 && str[i] < 127)
		{
			if (checker == 0)
			{
				count++;
				checker = 1;
			}
			i++;
		}
	}
	return (count);
}

char	*sub_str_extracter(char *str)
{
	char	*sub_str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[len] && (str[len] > 32 && str[len] < 127))
		len++;
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return NULL;
	while (str[i] && (str[i] > 32 && str[i] < 127))
	{
		sub_str[i] = str[i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	**ft_split(char *str)
{
	char	**array;
	int		size_arr;
	int		j;
	int		checker;

	j = 0;
	checker = 0;
	size_arr = word_counter(str);
	array = malloc(sizeof(char*) * (size_arr + 1));
	if (!array)
		return NULL;
	while (*str)
	{
		while (*str == 32 || (*str >= 9 && *str <= 13))
		{
			str++;
			checker = 0;
		}
		while (*str > 32 && *str < 127)
		{
			if (checker == 0)
			{
				array[j] = sub_str_extracter(str);
				j++;
				checker = 1;
			}
			str++;
		}
	}
	array[j] = 0;
	return (array);
}


int		main()
{
	char	**array;
	int		i;

	i = 0;
	array = ft_split("a   b");
	while (array[i])
	{
		printf("str:%s\n", array[i]);
		i++;
	}
}








// IGNORE THE NEXT ONE


#include <stdlib.h>

int	ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
}

char	*word_dupe(char *str)
{
	int i = 0;
	int len = ft_wordlen(str);
	char *word = malloc(sizeof(char) * (len + 1));
	
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
{
	int word_index = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str);
		++word_index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
}

int		count_words(char *str)
{
	int num_words = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		++num_words;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	return (num_words);
}

char	**ft_split(char *str)
{
	int		num_words;
	char	**array;
	
	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1));
	
	array[num_words] = 0;
	fill_words(array, str);
	return (array);
}

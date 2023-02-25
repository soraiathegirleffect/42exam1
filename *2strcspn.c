
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	size_t k = 0;

	while(s[i])
	{
		while (reject[k])
		{
			if (reject [k] == s[i])
				return (i);
			k++;
		}
		k = 0;
		i++;
	}
	return (i);
}




//string.h for size_t
//The strcspn() function calculates the length of the initial segment  of s which consists entirely of bytes not in reject.
//The strcspn() function returns the number of bytes in the initial segment of s which are not in the string reject.


// int	main(void)
// {
// 	printf("%lu\n", ft_strcspn("test", "es"));
// 	printf("%lu\n", strcspn("test", "es"));
// printf("%lu\n", ft_strcspn("test", "f"));
// 	printf("%lu\n", strcspn("test", "f"));
// }

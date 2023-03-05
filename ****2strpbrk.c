Reproduce exactly the behavior of the function strpbrk
(man strpbrk).
The function should be prototyped as follows:
char	*ft_strpbrk(const char *s1, const char *s2);
*/

#include <stdio.h>
#include <string.h>
// not forget the associated library

char *ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int b;

    i = 0;
    b = 0;
    if (!s1 || !s2) // protecting conditions
        return (0);
    while (s1[i])
    {
        while (s2[b])
        {
            if (s1[i] == s2[b])
                return ((char *)(s1 + i));
            b++;
        }
        b = 0;
        i++;
    }
    return (NULL);
}


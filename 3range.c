#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	size;
	int	*ret;
	int	*ptr;

	size = end - start;
	if (size)
	{
		ptr = (int *)malloc(sizeof(int) * size);
		if (ptr)
		{
			ret = ptr;
			while (start <= end)
			{
				*ptr = start;
				ptr++;
				start++;
			}
			return (ret);
		}
	}
	return (NULL);
}

// orrrrrrrrrrr
Write the following function:
int     *ft_range(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.
Examples:
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int *array;
	long int size;
	long int i;

	i = 0;
	size = end - start;
	if (size < 0)
		size *= -1;
	size++;
	array = malloc(sizeof(int) * size);
	if (!array)
		return 0;
	if (start == end)
		array[0] = start;
	if (start < end)
	{
		while (i < size)
		{
			array[i] = start;
			start++;
			i++;
		}
	}
	else if (start > end)
	{
		while (i < size)
		{
			array[i] = start;
			start--;
			i++;

		}
	}
	return (array);
}

#include <stdlib.h>

int		absolute_value(int n);

int		*ft_rrange(int start, int end)
{
	int number_of_ints;
	int *array;
	int step;
	int i;

	number_of_ints = 1 + absolute_value(end - start);
	array = malloc(sizeof(int) * number_of_ints);

	if (start > end)
		step = 1;
	else
		step = -1;

	i = 0;
	while (i < number_of_ints)
	{
		array[i] = end;
		end = end + step;
		++i;
	}
	return (array);
}

// orrrrrrrrrrr
Write the following function:
int     *ft_rrange(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.
Examples:
- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int *array;
	long int i;
	long int size;

	i = 0;
	size = end - start;
	if (size < 0)
		size *= -1;
	size++;
	array = malloc(sizeof(int) * size);
	if (!array)
		return 0;
	if (start == end)
		array[i] = start;
	else if (end > start)
	{
		while (i < size)
		{
			array[i] = end;
			end--;
			i++;

		}
	}
	else if (start > end)
	{
		while (i < size)
		{
			array[i] = end;
			end++;
			i++;
		}
	}
	return (array);
}

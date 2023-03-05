#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}



//orrrrrrrrrrrrr
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
Your function must be declared as follows:
void	print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 0;
	while (i < 8)
	{
		if((octet << i) & 128)
			write (1, "1", 1);
		else
			write (1, "0", 1);
		i++;
	}
}

void	print_bits2(unsigned char octet)
{
	int i = 7;
	while (i >= 0)
	{
		if ((octet >> i) & 1)
			write (1, "1", 1);
		else
			write (1, "0", 1);
		i--;
	}
}

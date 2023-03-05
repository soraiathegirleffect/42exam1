unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}



//orrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.
Your function must be declared as follows:
unsigned char	reverse_bits(unsigned char octet);
Example:
  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char byte;
	int i;
	int n;
	int power;

	byte = 0;
	i = 7;
	while (i >= 0)
	{
		if (octet << i & 128)
		{
			n = 0;
			power = 1;
			if (i == 0)
				power = 1;
			while (n < i)
			{
				power *= 2;
				n++;
			}
			byte += power;
		}
		i--;
	}
	return (byte);
}

/* another form to do */
unsigned char reverse_bits2(unsigned char octet)
{
	int i;
	unsigned char c;

	c = 0;
	i = 0;
	while (i < 4)
	{
		if (octet >> i & 1)
			c += 1 << (7 - i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (octet << i & 128)
			c += 1 << i;
		i++;
	}
	return (c);
}

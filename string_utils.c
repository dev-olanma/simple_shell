#include "pod.h"
/**
 * _atoi - converts a string to an integer
 * @str: string to convert
 *
 * Return: integer value of string
 */
int _atoi(char *str)
{
	unsigned int i = 0, j, k, len, num = 0, sign = 1;

	while (*(str + i) != '\0')
	{
		i++;
	}

	for (j = 0; j < i; j++)
	{
		if (*(str + j) >= '0' && *(str + j) <= '9')
			break;
	}

	for (k = j; k < i; k++)
	{
		if (!(*(str + k) >= '0' && *(str + k) <= '9'))
			break;
	}

	for (len = 0; len < j; len++)
	{
		if (*(str + len) == '-')
			sign *= -1;
	}

	len = k - j;

	while (len >= 1)
	{
		num = (num * 10) + (*(str + j) - '0');
		j++;
		len--;
	}

	num *= sign;
	return (num);
}

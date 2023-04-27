#include "pod.h"

/**
* main - Counts numbers 1-20 and writes them to standard output
*
* Return: 0 if successful
*/
int main(void)
{
	char buffer[3];
	int n, i;

	for (i = 1; i <= 20; i++)
	{
		n = sprintf(buffer, "%d\n", i);
		write(STDOUT_FILENO, buffer, n);
	}

return (0);
}

#include "pod.h"

/**
 * main - main shell file
 * @argc: number of arguments passed to the program
 * @argv: array of argument strings passed to the program
 * @envp: array of environment variable strings passed to the program
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *envp[])
{
	if (argc == 1)
	{
		_noargv(argv, envp);
	}
	else if (argc == 2)
	{
		_singleargv(argv, envp);
	}
	else
	{
		write(STDIN_FILENO, "ERROR: Incorrect number of arguments\n", 38);
	}
	return (0);
}


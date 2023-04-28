#include "pod.h"
/**
 * check_semicolon - search if in the input there is a ";" or a ";;"
 * @input: complete input of user
 * @loop_num: number of actual loop
 * @args: input argument
 * Return: 1 if find ";" or ";;" or 0 if not
 */
int check_semicolon(char *input, int loop_num, char **args)
{
	int valid = 0, i = 0;

	while (input[i] != '\0')
	{
		if (input[0] == ';')
		{
			valid = 1;
			write(STDERR_FILENO, args[0], _strlen(args[0]));
			write(STDERR_FILENO, ": ", 2);
			print_number(loop_num);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "Syntax error: ", 14);
			write(STDERR_FILENO, ";", 1);
			write(STDERR_FILENO, " unexpected\n", 12);
			break;
		}
		if (input[i] == ';' && input[i + 1] == ';')
		{
			valid = 1;
			write(STDERR_FILENO, args[0], _strlen(args[0]));
			write(STDERR_FILENO, ": ", 2);
			print_number(loop_num);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "Syntax error: ", 14);
			write(STDERR_FILENO, ";;", 2);
			write(STDERR_FILENO, " unexpected\n", 12);
			break;
		}
		i++;
	}
	return (valid);
}
/**
 * remove_comments - remove commentaries
 * @input: input of user
 * Return: the new input
 */
char *remove_comments(char *input)
{
	int start = 0, end = 0, flag = 0;

	while (input[end] != '\0')
		end++;
	while (input[start] != '\0')
	{
		if (input[0] == '#')
		{
			flag = 1;
			break;
		if (input[start] == '#' && input[start - 1] == ' ')
		{
			flag = 1;
			break;
		}
		start++;
		}
		if (flag == 1)
		{
			for (; start < end; start++)
				input[start] = 0;
		}
		return (input);
	}


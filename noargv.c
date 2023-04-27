#include "pod.h"

/**
 *rev - gets if the input of user is env, cd
 *@p: array of pointers to user tokens
 *@loop: pointer to loop counter variables
 *@line: string containing user user
 *@args: arguments in user input
 *@env_vars: copy of environment variable
 *@num_env_vars: number of elements in env_vars
 *@full_input: complete user input string
 * Return: -1 if the input is different to env or cd
 *or 0 if the input is cd or env
 */
int rev(char **p, int loop, char *line, char **args, char ***env_vars,
int *num_env_vars, char *full_input)
{

	int unset = 0, set = 0, other = -1, ex = 0, hel = 0;
	int env = 0, cd = 0;

	unset = _isunsetenv(p, *env_vars, num_env_vars, loop, args);
	if (unset == 0)
		return (unset);
	set = _issetenv(p, env_vars, num_env_vars, loop, args);
	if (set == 0)
		return (set);
	ex = _isexit(p, loop, line, args, *env_vars, full_input);
	if (ex == 0)
		return (ex);
	hel = _ishelp(p, loop, args, *env_vars);
	if (hel == 0)
		return (hel);
	env = _isenv(p, *env_vars);
	cd = _iscd(p, loop, args, *env_vars);
	if (env == 0)
		return (env);
	if (cd == 0)
		return (cd);
	return (other);
}

/**
 * functions - performs all the funcitons based on inputs
 *@line: input string from user
 *@loop: number of loops
 *@argv: array of argumnets
 *@env_vars: copy of environment variables
 *@num_env_vars: number of elements in env_vars
 *@full_input: complete input of user
 */
void functions(char *line, int loop, char *argv[], char ***env_vars,
int *num_env_vars, char *full_input)
{
	char **args = NULL;
	int value = 1, i = 0;

	line = _comments(line);
	args = parsing(line);
	if (args)
	{
		for (i = 0; args[i] != NULL; i++);

		value = rev(args, loop, line, argv, env_vars, num_env_vars, full_input);
		if (value != 0)
		{
			args = checkbin(args, *env_vars);
			if (args)
			_frk(args, line, i, loop, argv, *num_env_vars, *env_vars, full_input);
		}
		free_grid(args, i);
		free(line);
	}
	else
	{
		free(line);
		fflush(STDIN_FILENO);
	}
	_put_err(args, loop, 0, argv);
}

/**
 * _noargv - shell behaviour when called without a filename
 * @argv: arry of pointers to arguments in the input
 * @envp: environment variables
 */
void _noargv(char *argv[], char *envp[])
{
	char *line = NULL, **env_vars = NULL, *p = NULL, *pr1 = NULL;
	int num_env_vars = 0, *loop_ptr, i = 0, sem_present = 0;
	static int loop;

	loop = 0;
	loop_ptr = &loop;
	while (1)
	{
		if (loop == 0)
		{
			env_vars = create_env(envp);
			for (num_env_vars = 0; env_vars[num_env_vars] != NULL; num_env_vars++);
		}
		line = _getline(loop_ptr, env_vars, num_env_vars);
		sem_present = semicolon(line, loop, argv);
		if (!(sem_present == 1))
		{
			p = _strtoky2(line, ";\n");
			while (p)
			{
				pr1 = _calloc(_strlen(p) + 2, sizeof(char));
				for (i = 0; p[i] != '\0'; i++)
				pr1[i] = p[i];
				pr1[i] = '\n';
				pr1[i + 1] = '\0';
				functions(pr1, loop, argv, &env_vars, &num_env_vars, line);
				p = _strtoky2(NULL, ";\n");
			}
		}
	}
	free(line);
}

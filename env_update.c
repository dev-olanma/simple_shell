#include "pod.h"
/**
 * update_pwd_env - change the PWD environment variable
 * @buf: pointer to old pwd
 * @my_env: copy of environmental variable
 */
void update_pwd_env(char *buf, char **my_env)
{
	char *entire_pwd;
	char str[] = "PWD=";
	int i = 0, j = 0, cont = 0, k = 0, my_env_len = 0, buf_len = 0;

	entire_pwd = str_concat(str, buf);
	for (i = 0; my_env[i] != NULL; i++, cont = 0)
	{
		for (j = 0; my_env[i][j] != '\0' && j < 4; j++)
		{
			if (my_env[i][j] == str[j])
			{
				cont++;
			}
			else
				break;
		}
		if (cont == 4)
			break;
	}
	if (cont == 4)
	{
		my_env_len = _strlen(my_env[i]);
		buf_len = _strlen(entire_pwd);
		if (buf_len < my_env_len)
		{
			for (k = 0; entire_pwd[k] != '\0'; k++)
				my_env[i][k] = entire_pwd[k];
			for (; k < my_env_len; k++)
				my_env[i][k] = 0;
		}
		else
		{
			my_env[i] = _realloc(my_env[i], my_env_len, buf_len + 1);
			for (k = 0; entire_pwd[k] != '\0'; k++)
				my_env[i][k] = entire_pwd[k];
		}
	}
	free(entire_pwd);
}

/**
 * update_oldpwd_env - change the OLDPWD environment variable
 * @buf: pointer to old pwd
 * @my_env: copy of environmental variable
 */
void update_oldpwd_env(char *buf, char **my_env)
{
	char *entire_pwd;
	char str[] = "OLDPWD=";
	int i = 0, j = 0, cont = 0, k = 0, my_env_len = 0, buf_len = 0;

	entire_pwd = str_concat(str, buf);
	for (i = 0; my_env[i] != NULL; i++)
	{
		for (j = 0; my_env[i][j] != '\0' && j < 7; j++)
		{
			if (my_env[i][j] == str[j])
				cont++;
			else
				break;
		}
		if (cont == 7)
			break;
	}
	if (cont == 7)
	{
		my_env_len = _strlen(my_env[i]);
		buf_len = _strlen(entire_pwd);
		if (buf_len < my_env_len)
		{
			for (k = 0; entire_pwd[k] != '\0'; k++)
				my_env[i][k] = entire_pwd[k];
			for (; k < my_env_len; k++)
				my_env[i][k] = 0;
		}
		else
		{
			my_env[i] = _realloc(my_env[i], my_env_len, buf_len + 1);
			for (k = 0; entire_pwd[k] != '\0'; k++)
				my_env[i][k] = entire_pwd[k];
		}
	}
	free(entire_pwd);
}


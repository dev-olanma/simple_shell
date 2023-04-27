#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	char *tokens[MAX_NUM_TOKENS];
	int num_tokens;
	pid_t pid;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, "#Shelly&", strlen("#Shelly& "));

		getline(&input, &input_size, stdin);
		if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}

		num_tokens = 0;
		tokens[num_tokens] = strtok(input, " ");
		while (tokens[num_tokens] != NULL && num_tokens < MAX_NUM_TOKENS)
		{
		num_tokens++;
			tokens[num_tokens] = strtok(NULL, " ");
		}
		tokens[num_tokens] = NULL;

		pid = fork();
		if (pid == 0)
		{
			if (execvp(tokens[0], tokens) == -1)
			{
				printf("Invalid command.\n");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			printf("Error: fork failed.\n");
		}
		else
		{
			do {
			waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}

	free(input);
	return (0);
}

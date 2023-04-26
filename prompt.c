#include "pod.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "sys/wait.h"

/**
 * Main - Entry point for the program.
 *
 * This function reads user input, performs calculations, and outputs results.
 * It takes no arguments and returns an integer value indicating exit status.
 *
 * Return: -1
 */
int main(void)
{
        char *caller = "#shelly& ";
        char *lineptr = NULL;
        size_t n = 0;
        ssize_t read_newchar;


        while (1)
        {
                write(STDOUT_FILENO, caller, strlen(caller));
                read_newchar = getline(&lineptr, &n, stdin);

                if (read_newchar == -1)
                {
                        perror("Escape shell----\n");
                        free(lineptr);
                        return (-1);
                } 
                /* Remove the new line character from the end of input */
                lineptr[strcspn(lineptr, "\n")] = '\0';

                /* Split the input into commands and arguments */
                char *command = NULL;
                char *arg = NULL;
                char *token = strtok(lineptr, " ");

                if (token)
                {
                        command = token;
                        token = strtok(NULL, " ");
                        if (token)
                        {
                                arg = token;
                        }
                }

                /* Handle built-in shell commands */
                if (command)
                {
                        if (strcmp(command, "cd") == 0)
                        {
                                if (arg)
                                {
                                        if (chdir(arg) == -1)
                                        {
                                                perror("cd");
                                        }
                                }
                                else
                                {
                                        char *home = getenv("HOME");
                                        if (chdir(home) == -1)
                                        {
                                                perror("cd");
                                        }
                                }
                                continue;
                        }
                        else if (strcmp(command, "exit") == 0)
                        {
                                free(lineptr);
                                exit(0);
                        }
                        else if (strcmp(command, "echo") == 0)
                        {
                                if (arg)
                                {
                                        printf("%s\n", arg);
                                }
                                continue;
                        }
                }

                /* Execute the command with execve */
                if (command)
                {
                        pid_t pid = fork();
                        if (pid == -1)
                        {
                                perror("fork");
                                exit(EXIT_FAILURE);
                        }
                        else if (pid == 0)
                        {
                                /* Child process */
                                char *argv[] = {command, arg, NULL};
                                char *envp[] = {NULL};
                                if (execvp(command, argv) == -1)
                                {
                                        perror(command);
                                        exit(EXIT_FAILURE);
                                }
                        }
                        else
                        {
                                /* Parent process */
                                int status;
                                if (waitpid(pid, &status, 0) == -1)
                                {
                                        perror("waitpid");
                                        exit(EXIT_FAILURE);
                                }
                        }
                }
        }
        free(lineptr);
        return (0);
}


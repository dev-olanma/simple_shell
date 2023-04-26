#include "pod.h"
#include "string.h"

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
        char *lineptr;
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

                /*Remove the new line character from the end of input*/
                lineptr[strcspn(lineptr, "\n")] = '\0';

                /*Split the input into commands and arguements*/
                char *command;
                char *arg;

                /*Execute the command with execve*/
                if (command)
                {
                        pid_t pid = fork();
                        if (pid == -1)
                        {
                                perror("fork");
                                exit(EXIT_FAILURE);
                        }
                        else if(pid == 0)
                        {
                                /* Child proces*/
                char *argv[] = {command, arg, NULL};
                char *envp[] = {NULL};
                execve(command, argv, envp);

                /* If execve returns, it means an error occurred*/
                perror(command);
                exit(EXIT_FAILURE);
            }
            else
            {
                /* Parent process*/
                int status;
                if (waitpid(pid, &status, 0) == -1)
                {
                    perror("waitpid");
                    exit(EXIT_FAILURE);
                                }
                        }
                }
        }
        free (lineptr);
return (0);
}

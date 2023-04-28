#ifndef _POD_H_
#define _POD_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void *_calloc(unsigned int num_elements, unsigned int element_size);
int main(int argc, char *argv[], char *envp[]);

/*function of the pod*/
void _noargv(char *argv[], char *envp[]);
void _singleargv(char *argv[], char *envp[]);
int rev(char **p, int loop, char *line, char **args, char ***env_vars, int *num_env_vars, char *full_input);
void functions(char *line, int loop, char *argv[], char ***env_vars, int *num_env_vars, char *full_input);

/* --- Global Variables --- */

/* is_env - finds if line input is env */
int is_env(char **args, char **myenv);

/* create_env - creates a copy of the environmental variables */
char **create_env(char *envp[]);

/* env - function to print the environment variables */
void env(char **myenv);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
void executev(const char *pathname, char *const argv[], char *const envp[])
{
	if (execve(pathname, argv, envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

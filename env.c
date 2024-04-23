#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
extern char **environ; /* need to declare environ on the main unix shell*/
/*
 * This will just print the environment and will depend on environ
 *
 */
void penv()
{
char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}

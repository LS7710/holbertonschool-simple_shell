#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
#define MAX_COMMAND_LENGTH 1024
int main()
{
char command[MAX_COMMAND_LENGTH];
while (1)
{
printf("$ ");
fflush(stdout);
if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
if (feof(stdin))
{
break;
} else
{
perror("fgets");
continue;
}
}
command[strcspn(command, "\n")] = '\0';
if (strcmp(command, "exit") == 0)
{
break;
}
commandexecutor(command);
}
return 0;
}

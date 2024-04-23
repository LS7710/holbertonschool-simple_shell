#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 1024

void commandexecutor(const char *command)
{
pid_t pid = fork();
if (pid < 0) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid == 0) {
char *args[MAX_COMMAND_LENGTH];
char *token = strtok((char *)command, " ");
int i = 0;
while (token != NULL) {
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;
execvp(args[0], args);
perror("execvp");
exit(EXIT_FAILURE);
} else {
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status)) {
if (WEXITSTATUS(status) != 0) {
fprintf(stderr, "Command returned non-zero exit status: %d\n", WEXITSTATUS(status));
}
} else if (WIFSIGNALED(status)) {
fprintf(stderr, "Command terminated by signal: %d\n", WTERMSIG(status));
} else {
fprintf(stderr, "Command terminated abnormally\n");
}
}
}

#include "shell.h"

void execute_command(char *cmd)
{
    char *argv[10];
    int i = 0;
    pid_t pid;

    argv[i] = strtok(cmd, " \n");

    while (argv[i] != NULL && i < 9) {
        argv[++i] = strtok(NULL, " \n");
    }

    if (argv[0] != NULL) {
        if (strcmp(argv[0], "exit") == 0)
    		exit(0);

        pid = fork();
	if (pid == 0) {

    		if (execvp(argv[0], argv) == -1) {
                perror("hsh");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {

    		perror("hsh");
        } else {

            wait(NULL);
        }
    }
}


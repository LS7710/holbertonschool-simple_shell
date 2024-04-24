#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *prompt = "(===||:::::::::::::::> ";


    printf(" _       __     __                             __  \n"
           "| |     / /__  / /________  ____ ___  ___     / /  \n"
           "| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / /   \n"
           "| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  /_/    \n"
           "|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___(_)(_)     \n"
           "                                                    \n");

    while (printf("%s", prompt), (read = getline(&line, &len, stdin)) != -1)
    {
        execute_command(line);
    }

    free(line);
    return (EXIT_SUCCESS);
}


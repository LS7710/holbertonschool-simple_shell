#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *prompt = "$ ";

    while (printf("%s", prompt), (read = getline(&line, &len, stdin)) != -1)
    {
        execute_command(line);
    }

    free(line);
    return (EXIT_SUCCESS);
}


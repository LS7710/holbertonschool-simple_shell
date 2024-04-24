#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *prompt = "$ ";

	do {
	
	if (isatty(STDIN_FILENO)) {
	printf("%s", prompt);

	}

	read = getline(&line, &len, stdin);
	if (read != -1) {
	execute_command(line);
	}
	} while (read != -1);

free(line);
return (EXIT_SUCCESS);
}

#include <unistd.h>
#include "shell.h"
/**
 * remove_newline - removes new lines
 * @line: the line from stdin
 *
 * Return: void
 */
void remove_newline(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
		i++;
	}
}

/**
 * main - main function for our shell
 *
 * Return: last_status
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int last_status = 0;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		remove_newline(line);

		last_status = execute_command(line);
	}
	free(line);
	return (last_status);
}

#include "shell.h"

/**
* read_command - It reads the command written in standard input.
* @line: address of line storage
*/

void read_command(char **line)
{
size_t len = 0;
ssize_t nread;

nread = getline(line, &len, stdin);
if (nread == -1)
{
free(*line);
exit(EXIT_SUCCESS);
}
if ((*line)[nread - 1] == '\n')
{
(*line)[nread - 1] = '\0';
}
}

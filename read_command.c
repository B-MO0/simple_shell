#include "shell.h"
/*
* read_command - It reads the command written in standard input.
* @line: address of line storage
*/
void read_command(char *line)
{
if (!gets(line, MAXLINE, stdin))
{
exit(EXIT_SUCCESS);
}
size_t length = strlen(line);
if (line[length - 1] == '\n')
{
line[length - 1] = '\0';
}
}

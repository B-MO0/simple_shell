#include "shell.h"

/**
* parse_command - Parses the line into an array of arguments.
* @line: The input string to parse.
* @argv: The array to store the arguments.
*
* Return: 1 if argument is found, 0 if not.
*/

int parse_command(char *line, char **argv)
{
char *token;
int i = 0;

token = strtok(line, " ");
while (token != NULL)
{
argv[i++] = token;
if (i >= MAX_ARGS)
{
break;
}
token = strtok(NULL, " ");
}
argv[i] = NULL;
return (i > 0);
}

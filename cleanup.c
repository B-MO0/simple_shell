#include "shell.h"

/**
*cleanup - Free the command line.
*
*/

char *line = NULL;
char *argv[MAX_ARGS] = {NULL};

void cleanup(void)
{
if (line) {
free(line);
line = NULL;
}
}

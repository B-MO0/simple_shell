#include "shell.h"

/**
* find_command_in_path - Searches for the command in the directories.
* @cmd: command.
*
* Return: Path to the command if found, if not NULL.
*/
char *find_command(char *cmd)
{
char *path = getenv("PATH");
char *path_copy = strdup(path);
if (!path_copy)
{
perror("strdup");
return (NULL);
}

char *full_path = malloc(MAX_LINE);
if (!full_path)
{
perror("malloc");
free(path_copy);
return (NULL);
}

char *dir = strtok(path_copy, ":");
while (dir != NULL)
{
snprintf(full_path, MAX_LINE, "%s/%s", dir, cmd);
if (access(full_path, X_OK) == 0)
{
free(path_copy);
return (full_path);
}
dir = strtok(NULL, ":");
}

free(path_copy);
free(full_path);
return (NULL);
}

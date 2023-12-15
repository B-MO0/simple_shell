#include "shell.h"

/**
* find_command - Searches for the command in the directories.
* @cmd: command.
*
* Return: Path to the command if found, if not NULL.
*/

char *find_command(char *cmd)
{
char *path = getenv("PATH");
char *path_copy, *full_path, *dir;
int path_len, cmd_len, full_path_len;

if (!path)
return (NULL);

for (path_len = 0; path[path_len]; path_len++);
path_copy = malloc(path_len + 1);
if (!path_copy)
{
perror("malloc");
return (NULL);
}

for (int i = 0; path[i]; i++)
path_copy[i] = path[i];
path_copy[path_len] = '\0';

full_path = malloc(MAX_LINE);
if (!full_path)
{
perror("malloc");
free(path_copy);
return (NULL);
}

dir = strtok(path_copy, ":");
while (dir)
{
for (cmd_len = 0; cmd[cmd_len]; cmd_len++);
for (full_path_len = 0; dir[full_path_len]; full_path_len++);
if (full_path_len + cmd_len + 2 > MAX_LINE)
{
dir = strtok(NULL, ":");
continue;
}

int i = 0;
for (i = 0; dir[i]; i++)
full_path[i] = dir[i];
full_path[i] = '/';
for (int j = 0; cmd[j]; j++)
full_path[i + 1 + j] = cmd[j];
full_path[i + 1 + cmd_len] = '\0';

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

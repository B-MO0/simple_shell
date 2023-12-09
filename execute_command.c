#include "shell.h"

/**
* execute_command - Executes a command.
* @argv: array of arguments.
*/
void execute_command(char **argv)
{
pid_t pid;
int status;

pid = fork();
if (pid < 0)
{
perror("fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(argv[0], argv, NULL) == -1)
{
perror("execve failed");
exit(EXIT_FAILURE);
}
}
else
{
do
{
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
}

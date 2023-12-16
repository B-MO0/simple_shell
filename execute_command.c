#include "shell.h"

/**
* execute_command - Executes a command.
* @argv: array of arguments.
*/

void execute_command(char **argv) {
pid_t pid;
int status;
char *cmd_path = find_command(argv[0]);

if (cmd_path == NULL) {
fprintf(stderr, "%s: command not found\n", argv[0]);
return;
}

pid = fork();
if (pid == 0) {

execve(cmd_path, argv, environ);
perror("execve");
exit(EXIT_FAILURE);
} else if (pid > 0) {

do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
} else {
perror("fork");
cleanup();
exit(EXIT_FAILURE);
}

free(cmd_path);
}



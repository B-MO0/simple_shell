#ifndef SHELL_H
#define SHELL_H

/*globals*/
#define MAX_LINE 1024
#define MAX_ARGS 64

/* allowed functions header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>

/*Prototypes*/
void display_prompt();
void read_command(char* line);
int run_shell();

#endif 

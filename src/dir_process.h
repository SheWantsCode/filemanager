#ifndef dir_process
#define dir_process

#include <stdbool.h>
#include <sys/stat.h>
#include "cli_parser.h"
#include <dirent.h>

#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void make_path(cliArgs, char*, char**);

void cut_path(char**, char*);

void print_file(cliArgs, struct dirent*, char*);

void print_perms(mode_t);

#endif
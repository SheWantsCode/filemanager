#ifndef dir_process
#define dir_process

#include <stdbool.h>
#include <sys/stat.h>
#include "cli_parser.h"
#include <dirent.h>

#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// In make_path func make path for file/directory with options in CliArgs
void make_path(cliArgs, char*, char**);

// In the cut_path function cut out the path to the file, leaving only name of file
void cut_path(char**, char*);

void print_file(cliArgs, struct dirent*, char*);

void print_perms(mode_t);

#endif
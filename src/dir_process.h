#ifndef dir_process
#define dir_process

#include <stdbool.h>
#include <sys/stat.h>
#include "cli_parser.h"

char* show_dir(char* path, char* file_name, bool lname_flag);

// In make_path func make path for file/directory with options in CliArgs
void make_path(cliArgs cliArgs, char* path, char** full_path);

// In the cut_path function cut out the path to the file, leaving only name of file
char* cut_path(char* full_path);

void print_perms(mode_t perms);

#endif
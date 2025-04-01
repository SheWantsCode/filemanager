#ifndef dir_process
#define dir_process

#include <stdbool.h>
#include <sys/stat.h>

char* show_dir(char* path, char* file_name, bool lname_flag);

void print_perms(mode_t perms);

#endif
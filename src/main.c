#include <stdio.h>
#include <string.h>
#include "cli_parser.h"
#include "dir_process.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

// Set output colors
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char* argv[])
{
    cliArgs cli = cli_parser(argc, argv);
    struct dirent* dp;
    struct stat statbuf;
    char* dir_file;
    DIR* dir = opendir(cli.current_dir);
    while ((dp = readdir(dir)))
    {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        dir_file = show_dir(cli.current_dir, dp->d_name, cli.lname_flag);
        if (dp->d_type == DT_DIR)
        {
            printf(ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET, dir_file);
        }
        if (dp->d_type == DT_REG)
        {
            stat(dir_file, &statbuf);
            print_perms(statbuf.st_mode);
            printf("%s\n", dir_file);
        }

        free(dir_file);
    }
    closedir(dir);
    
    return 0;
}
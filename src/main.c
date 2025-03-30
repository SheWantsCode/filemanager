#include <stdio.h>
#include <string.h>
#include "cli_parser.h"
#include "dir_process.h"
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    cliArgs cli = cli_parser(argc, argv);
    struct dirent* dp;
    char* dir_file;
    DIR* dir = opendir(cli.current_dir);
    while ((dp = readdir(dir)))
    {
        dir_file = show_dir(cli.current_dir, dp->d_name, cli.lname_flag);
        printf("%s\n", dir_file);
        free(dir_file);
    }
    closedir(dir);
    
    return 0;
}
#include "cli_parser.h"
#include "dir_process.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>



int main(int argc, char* argv[])
{
    cliArgs cli = cli_parser(argc, argv);
    struct dirent* dp;
    char* path_to_file;
    DIR* dir = opendir(cli.current_dir);
    while ((dp = readdir(dir)))
    {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        make_path(cli, dp->d_name, &path_to_file);

        print_file(cli, dp, path_to_file);

        free(path_to_file);
    }
    closedir(dir);
    
    return 0;
}
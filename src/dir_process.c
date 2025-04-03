#include "dir_process.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <math.h>

void make_path(cliArgs cliArgs, char* file_name, char** full_path)
{
    size_t path_len = strlen(cliArgs.current_dir);
    size_t file_len = strlen(file_name);
    *full_path = malloc((path_len + file_len + 1 + 1));
    if (*full_path == NULL)
    {
        fprintf(stderr, "Memory allocation error.");
        exit(1);
    }
    strcpy(*full_path, cliArgs.current_dir);
    for (int i = path_len + 1, j = 0; (i < path_len + file_len + 1) && (j < file_len); i++, j++)
    {
        (*full_path)[i] = file_name[j];
    }
    (*full_path)[path_len] = '/';
    (*full_path)[path_len + file_len + 1] = '\0';
}

void cut_path(char** full_path, char* f_name)
{
    char* last_symbol = strrchr(*full_path, '/');
    int full_len = strlen(*full_path);
    int idx = last_symbol - (*full_path); // идекс откуда начинам
    int diff_len = full_len - idx; // разница

    for (int i = 0; i < diff_len; i++)
    {
        (*full_path)[i] = (*full_path)[i + idx];
    }
    (*full_path)[diff_len] = '\0';
}

void print_file(cliArgs cliArgs, struct dirent* dp, char* path)
{
    if (dp->d_type == DT_REG)
    {
        struct stat statbuf;
        stat(path, &statbuf);
        if (cliArgs.perms_flag)
        {
            print_perms(statbuf.st_mode);
        }

        if (cliArgs.size_flag)
        {
            printf(" %.4lfMb ", (float)statbuf.st_size / 1024.0 / 1024.0);
        }

        if (!cliArgs.lname_flag)
        {
            cut_path(&path, dp->d_name);
        }

        printf("%s\n", path);
    }
    if (dp->d_type == DT_DIR)
    {
        if (!cliArgs.lname_flag)
        {
            cut_path(&path, dp->d_name);
        }
        printf(ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET, path);
    }
}

void print_perms(mode_t perms)
{
    printf( (perms & S_IRUSR) ? "r" : "-");
    printf( (perms & S_IWUSR) ? "w" : "-");
    printf( (perms & S_IXUSR) ? "x" : "-");
    printf( (perms & S_IRGRP) ? "r" : "-");
    printf( (perms & S_IWGRP) ? "w" : "-");
    printf( (perms & S_IXGRP) ? "x" : "-");
    printf( (perms & S_IROTH) ? "r" : "-");
    printf( (perms & S_IWOTH) ? "w" : "-");
    printf( (perms & S_IXOTH) ? "x" : "-");
}
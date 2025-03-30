// #include "dir_process.h"
// #include <stdlib.h>
// #include <string.h>

// char* show_dir(char* path, char* file_name)
// {
//     char* full_path;
//     size_t path_len = strlen(path);
//     size_t file_len = strlen(file_name);
//     full_path = malloc((path_len + file_len + 1 + 1) * sizeof *full_path);
//     strcpy(full_path, path);
//     for (int i = path_len + 1, j = 0; (i < path_len + file_len) && (j < file_len); i++, j++)
//     {
//         full_path[i] = file_name[j];
//     }
//     full_path[path_len] = '/';
//     full_path[path_len + file_len] = '\0';
//     return full_path;
// }

#include "dir_process.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* show_dir(char* path, char* file_name, bool lname_flag)
{
    char* full_path;
    size_t path_len = strlen(path);
    size_t file_len = strlen(file_name);

    if (lname_flag)
    {
        full_path = malloc((path_len + file_len + 1 + 1) * sizeof *full_path);
        strcpy(full_path, path);
        for (int i = path_len + 1, j = 0; (i < path_len + file_len) && (j < file_len); i++, j++)
        {
            full_path[i] = file_name[j];
        }
        full_path[path_len] = '/';
        full_path[path_len + file_len] = '\0';
    }
    else
    {
        full_path = malloc(file_len + 1);
        strcpy(full_path, file_name);
        full_path[file_len] = '\0';
    }

    
    return full_path;
}
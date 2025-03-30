#include "cli_parser.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void about_app()
{
    printf("==============================\n");
    printf("| File manager by shewants   |\n");
    printf("| Version 0.0.1 - alfa       |\n");
    printf("==============================\n\n");
    printf("Hi, this utiliti gives you simple function such as:\n");
    printf("    - See all files in directory\n");
    printf("    - Create files in direcotory\n");
    printf("    - Copy and move files\n");
    printf("    - View information about files: size, access e.t.\n");
}

cliArgs cli_parser(int argc, char* argv[]) 
{
    cliArgs parsed = {0};
    parsed.current_dir = malloc(PATH_MAX);

    if (parsed.current_dir == NULL)
    {
        printf("Memory allocation error.\n");
        exit(1);
    }

    if (argc <= 1)
    {
        getcwd(parsed.current_dir, PATH_MAX);
        printf("No arguments. Use flag -h or --help for more information.\n");
        printf("\nWorking directory - %s", parsed.current_dir);
        exit(1);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
            {
                about_app();
                exit(1);
            }
            if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--directory") == 0)
            {
                strcpy(parsed.current_dir, argv[i + 1]);
                parsed.lname_flag = false;
                i++;
            }
            if (strcmp(argv[i], "-ld") == 0 || strcmp(argv[i], "--longdir") == 0)
            {
                parsed.current_dir = argv[i + 1];
                parsed.lname_flag = true;
                i++;
            }
        }
    }
    
    return parsed;
}

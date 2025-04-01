#include "cli_parser.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <getopt.h>

void about_app(void)
{
    printf("==============================\n");
    printf("| File manager by shewants   |\n");
    printf("| Version 0.0.1 - alfa       |\n");
    printf("==============================\n\n");
    printf("Hi, this tool gives you simple function such as:\n");
    printf("    - See all files in directory\n");
    printf("    - Create files in direcotory\n");
    printf("    - Copy and move files\n");
    printf("    - View information about files: size, access e.t.\n");
}

cliArgs cli_parser(int argc, char* argv[]) 
{
    int opt;
    if (argc == 0 || argv == NULL)
    {
        fprintf(stderr, "No arguments were given.");
    }

    cliArgs parsed = {0};
    parsed.current_dir = malloc(PATH_MAX);

    if (parsed.current_dir == NULL)
    {
        fprintf(stderr, "Memory allocation error.");
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

        struct option options[] = {
            { "help", no_argument, 0, 'h' },
            { "directory", required_argument, 0, 'd' },
            { "longdir", required_argument, 0, 'l' },
        };

        opterr = 0;
        while ((opt = getopt_long(argc, argv, "hd:l:", options, NULL)) != -1)
        {
            switch (opt)
            {
                case 'h':
                    about_app();
                    exit(0);
                case 'd':
                    parsed.lname_flag = false;
                    parsed.current_dir = optarg;
                    break;
                case 'l':
                    parsed.lname_flag = true;
                    parsed.current_dir = optarg;
                    break;
                case ':':
                    // printf("Option need an argument");
                    fprintf(stderr, "Missing argument.\n");
                    exit(1);
                case '?': 
                    fprintf(stderr, "Unknown option.\n"); 
                    exit(1);
            }
        }
    }
    
    return parsed;
}

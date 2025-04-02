#ifndef cliParser
#define cliParser

#include <stdbool.h>

typedef struct 
{
    char* current_dir;
    bool lname_flag;
    bool perms_flag;
    int argc;
} cliArgs;


void about_app(void);

cliArgs cli_parser(int argc, char* argv[]);

#endif
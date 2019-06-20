#include <stdio.h>
#include <string.h>
#include "lib/hello.h"

int is_command(char *original_str);

char *resolve_value(char *original_str, int target);

int main(int argc, char *argv[])
{
    char equal[] = "=";
    char *command;

    char *command_hello = "hello";

    while (argc > 0)
    {
        argc--;

        if (argv[argc][0] == '-' & argv[argc][1] == '-')
        {
            if (is_command(argv[argc]) == 0) 
            {
                command = resolve_value(argv[argc], equal[0]);

                if (strcmp(command, command_hello) == 0)
                {
                    hello();
                    break;
                }

                printf("No such command: %s\n", command);
                break;
            }
            printf("No served command \n");
            break;
        }
    }

    return 0;
}

int is_command(char *original_str)
{
    char *target_str = "--command";
    if (strstr(original_str, target_str) != NULL)
    {
        return 0;
    }

    return -1;
}

char *resolve_value(char *original_str, int target)
{
    char *pvalue;

    pvalue = strchr(original_str, target);

    return pvalue + 1;
}
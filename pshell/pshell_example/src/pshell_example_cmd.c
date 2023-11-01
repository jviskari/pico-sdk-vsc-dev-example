#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "pshell.h"

/*
  Function Declarations for builtin shell commands:
 */
static int cmd_help(char ** args);
static int cmd_exit(char ** args);
static int cmd_test(char ** args);

static const struct psh_cmd m_interface[] = { { "help", &cmd_help },
                                              { "exit", &cmd_exit },
                                              { "test", &cmd_test },
                                              { NULL, NULL } };

/**
   @brief  test commands
   @param args List of args, printed
   @return Always returns 1, to continue executing.
 */

static int cmd_test(char ** args)
{
    int i = 0;

    while (args[i] != NULL)
    {
        puts((const char *) args[i++]);
    }

    return 1;
}


/**
   @brief  print help.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
static int cmd_help(char ** args)
{
    int i;
    printf("Pico Shell\n");

    if (args[1] != NULL)
    {
        if (strcmp("exit", args[1]) == 0)
        {
            printf("exit - reboot pico board\n");
        }
        else if (strcmp("help", args[1]) == 0)
        {
            printf("help - usage: help <command>\n"); 
        }
        else if (strcmp("test", args[1]) == 0)
        {
            printf("test <arg1> <arg2> ... <argn>\n"); 
        }
    }
    else
    {
        printf("The following commands are available:\n");

        while (m_interface[i].cmd_str != NULL)
        {
            printf("  %s\n", m_interface[i].cmd_str);
            i++;
        }
    }

    return 1;
}

/**
   @brief command: exit.
   @param args List of args.
   @return Always returns 0 to terminate execution.
 */
static int cmd_exit(char ** args)
{
    return 0;
}

/**
   @brief Get command interface
   @return Returns pointer to interface array
 */
const struct psh_cmd * psh_example_get_cmd_interface()
{
    return &m_interface[0];
}
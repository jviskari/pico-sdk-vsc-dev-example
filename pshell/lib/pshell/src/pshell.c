
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pshell.h"

#define PSH_TOK_BUFSIZE 64
#define PSH_TOK_DELIM   " \t\r\n\a"


/**
   @brief Execute shell built-in or launch program.
   @param args Null terminated list of arguments.
   @return 1 if the shell should continue running, 0 if it should terminate
 */
static int psh_execute(char ** args, const struct psh_cmd * cmd_interface)
{
    int i = 0;

    if (args[0] == NULL)
    {
        puts("\nempty command\n");
        return 1;
    }

    while (cmd_interface[i].cmd_str != NULL)
    {
        if (strcmp(args[0], cmd_interface[i].cmd_str) == 0)
        {
            puts("\n");
            return (cmd_interface[i].cmd_func(args));
        }
        i++;
    }

    puts("\npsh: not found\n");
    return 1;
}


/**
   @brief Tokenize line.
   @param line The line.
   @return Null-terminated array of tokens.
 */
static char ** psh_split_line(char * line)
{
    int     bufsize  = PSH_TOK_BUFSIZE;
    int     position = 0;
    char ** tokens   = malloc(bufsize * sizeof(char *));
    char *  token, **tokens_backup;

    if (!tokens)
    {
        fprintf(stderr, "psh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, PSH_TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += PSH_TOK_BUFSIZE;
            tokens_backup = tokens;
            tokens        = realloc(tokens, bufsize * sizeof(char *));

            if (!tokens)
            {
                free(tokens_backup);
                fprintf(stderr, "psh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, PSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int pshell_run(void (*read_line_callback)(char * buffer, size_t size),
               const struct psh_cmd * cmd_interface)
{
    char *  line;
    char ** args;
    int     status;

    if (read_line_callback == NULL)
    {
        return -1;
    }

    line = (char *) malloc(LINE_BUFFER_SIZE * sizeof(char));

    if (line == NULL)
    {
        return -2;
    }

    do
    {
        printf("> ");
        read_line_callback(line, LINE_BUFFER_SIZE * sizeof(char));
        args   = psh_split_line(line);
        status = psh_execute(args, cmd_interface);
        free(args);
    } while (status);

    free(line);

    return 0;
}

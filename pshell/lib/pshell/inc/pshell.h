#ifndef _PSHELL_H_
#define _PSHELL_H_

#define LINE_BUFFER_SIZE (256)

struct psh_cmd
{
    char * cmd_str;
    int (*cmd_func)(char **);
};

void psh_read_line_stdin(char * buffer, size_t size);
int  pshell_run(void (*read_line_callback)(char * buffer, size_t size),
                const struct psh_cmd * cmd_interface);

#endif
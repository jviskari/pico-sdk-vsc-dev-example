#include <stdint.h>
#include <stdio.h>


void psh_read_line_stdin(char * buffer, size_t size)
{
    size_t position = 0;
    int    c;

    while (1)
    {
        // Read a character
        c = getchar();

        if (c == 'n' || c == '\r' || position >= (size - 1))
        {
            buffer[position] = '\0';
            return;
        }
        else
        {
            buffer[position] = c;
        }
        putchar(c);
        position++;
    }
}

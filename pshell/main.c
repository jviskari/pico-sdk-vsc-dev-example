#ifndef PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS
#define PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS (-1)
#endif


#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/binary_info.h>
#include <hardware/watchdog.h>

#include "pshell.h"          //pshell core
#include "pshell_example.h"  //example commands

static const char program_name_str[] = "PICO SHELL";

static void software_reset()
{
    puts("RESET\n");
    watchdog_enable(1, 1);
    while (1)
        ;
}

static void init()
{
    stdio_init_all();

    // wait for connection
    sleep_ms(5000);

    puts("Init\n");
    printf("%s\n", program_name_str);
}

int main()
{
    bi_decl(bi_program_description(program_name_str));

    const struct psh_cmd * iface = psh_example_get_cmd_interface();

    init();

    pshell_run(psh_read_line_stdin, iface);

    software_reset();
}

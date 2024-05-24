#include "cli.h"
#include "commands.h"


int main(void)
{
    char* HELP_TEXT = "Welocme to table cli!\nHere you can do some operations with it:";
    cli_handle_t cli = cli_init(HELP_TEXT, 300);
    table_handle_t table = table_init();
    table_args* table_command_args = malloc(sizeof(table_args));
    table_command_args->table = &table;
    cli_add_command(cli, get_add_command_config(table_command_args));
    cli_add_command(cli, get_sort_command_config(table_command_args));
    cli_add_command(cli, get_print_command_config(table_command_args));
    cli_add_command(cli, get_find_command_config(table_command_args));
    cli_run_until_eof(cli);
    cli_destroy(cli);
    free(table_command_args);
    table_destroy(table);
}

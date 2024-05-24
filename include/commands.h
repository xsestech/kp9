//
// Created by Alex on 21.04.2024.
//

#ifndef COMMANDS_H
#define COMMANDS_H

#include <float.h>

#include "table.h"
#include "cli.h"
#include "parse.h"

typedef struct {
  table_handle_t* table;
} table_args;


command_config_t get_add_command_config(table_args* tree_command_args);
command_config_t get_sort_command_config(table_args* tree_command_args);
command_config_t get_find_command_config(table_args* tree_command_args);
command_config_t get_print_command_config(table_args* tree_command_args);


#endif //COMMANDS_H

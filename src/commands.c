//
// Created by Alex on 21.04.2024.
//
#include "commands.h"

#define MAX_TOKENS 5


void add_command(char *args, void *command_config) {
    table_args command_args = to_command_config(table_args, command_config);
    char* tokens[MAX_TOKENS];
    int parsed_tokens = 0;
    parse_tokens(args, MAX_TOKENS, tokens, &parsed_tokens);
    double key = 0;
    if(parsed_tokens != 3) {
        fprintf(stderr, "Invalid args\n");
        return;
    }
    if (!parse_double(tokens[1], &key)) {
        fprintf(stderr, "Invalid key\n");
        return;
    }
    table_record_t record;
    record.key = key;
    size_t value_len = strlen(tokens[2]);
    size_t copy_size = value_len > TABLE_KEY_SIZE ? TABLE_KEY_SIZE : value_len;
    strncpy(record.value, tokens[2], copy_size);
    table_add_record(*command_args.table, record);
    printf("Record added\n");
}

void find_command(char *args, void *command_config) {
    table_args command_args = to_command_config(table_args, command_config);
    char* tokens[MAX_TOKENS];
    int parsed_tokens = 0;
    parse_tokens(args, MAX_TOKENS, tokens, &parsed_tokens);
    double key = 0;
    if(parsed_tokens != 2) {
        fprintf(stderr, "Invalid args\n");
        return;
    }
    if (!parse_double(tokens[1], &key)) {
        fprintf(stderr, "Invalid key\n");
        return;
    }
    table_record_t found_record;
    if (!table_find(*command_args.table, key, &found_record)) {
        fprintf(stderr, "Not found\n");
        return;
    }
    printf("Found record:\n");
    table_record_print(found_record);
}

void print_command(char* args, void *command_config) {
    table_args command_args = to_command_config(table_args, command_config);
    if(*command_args.table == NULL) {
        fprintf(stderr, "Can't print empty table\n");
        return;
    }
    table_print(*command_args.table);
}

void sort_command(char* args, void *command_config) {
    table_args command_args = to_command_config(table_args, command_config);
    if(*command_args.table == NULL) {
        fprintf(stderr, "Nothing to sort.\n");
        return;
    }
    table_sort(*command_args.table);
    printf("Sorted table\n");
}

command_config_t get_add_command_config(table_args* tree_command_args) {
    return cli_create_command('a', &add_command, "<key;value> add record ", tree_command_args);
}

command_config_t get_print_command_config(table_args* tree_command_args) {
    return cli_create_command('p', &print_command, "print table", tree_command_args);
}
command_config_t get_sort_command_config(table_args* tree_command_args) {
    return cli_create_command('s', &sort_command, "sort table", tree_command_args);
}
command_config_t get_find_command_config(table_args* tree_command_args) {
    return cli_create_command('f', &find_command, "<key> find record", tree_command_args);
}
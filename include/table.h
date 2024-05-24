//
// Created by Alex on 24.05.2024.
//

#ifndef TABLE_H
#define TABLE_H

#include "vector.h"
#include "stdio.h"
#include "shell_sort.h"

#ifndef TABLE_KEY_SIZE
#define TABLE_KEY_SIZE 100
#endif

#ifndef TABLE_KEY_CMP_EPS
#define TABLE_KEY_CMP_EPS 0.1
#endif

typedef struct {
  double key;
  char value[TABLE_KEY_SIZE];
} table_record_t;

typedef struct {
  table_record_t *table;
} table_t;

typedef table_t* table_handle_t;

table_handle_t table_init();
void table_destroy(table_handle_t table);
void table_add_record(table_handle_t table, table_record_t record);
void table_record_print(table_record_t record);
void table_print(table_handle_t table);
void table_sort(table_handle_t table);
bool table_find(table_handle_t table, double key, table_record_t* output);

#endif //TABLE_H

//
// Created by Alex on 24.05.2024.
//

#include "table.h"


table_handle_t table_init() {
  table_handle_t table = malloc(sizeof(table_t));
  table->table = NULL;
  return table;
}
void table_destroy(table_handle_t table) {
  vector_destroy(table->table);
  free(table);
}
void table_add_record(table_handle_t table, table_record_t record) {
  vector_push_back(table->table, record);
}
void table_record_print(table_record_t record) {
  printf("%lf %s\n", record.key, record.value);
}
void table_print(table_handle_t table) {
  printf("key value\n");
  if (table->table == NULL)
    return;
  for (int i = 0; i < vector_size(table->table); i++) {
    table_record_print(table->table[i]);
  }
}

int record_cmp(const void* a, const void* b) {
  double arg1 = ((table_record_t*)a)->key;
  double arg2 = ((table_record_t*)b)->key;

  if (fabs(arg1 - arg2) < TABLE_KEY_CMP_EPS) {
    return 0;
  }

  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

void table_sort(table_handle_t table) {
  shell_sort(table->table, vector_size(table->table), sizeof(table_record_t), record_cmp);
}

bool table_find(table_handle_t table, double key, table_record_t* output) {
  table_record_t dummy_record = {key, ""};
  table_record_t* found_record = bsearch(&dummy_record, table->table, vector_size(table->table), sizeof(table_record_t), record_cmp);
  if (found_record == NULL)
    return false;
  *output = *found_record;
  return true;
}

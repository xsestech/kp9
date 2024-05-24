//
// Created by Alex on 18.05.2024.
//

#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include <stddef.h>
#include <stdlib.h>

/**
 * Shell sort generic implementation
 * Usage is similar to qsort from stdlib
 * @param ptr array
 * @param count amount of elements
 * @param size size of one element
 * @param comp function, that returns 1 of a > b, -1 of a < b, 0 if a == b
 */
void shell_sort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*));

#endif //SHELL_SORT_H

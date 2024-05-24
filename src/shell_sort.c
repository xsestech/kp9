//
// Created by Alex on 18.05.2024.
//

#include "shell_sort.h"

/**
 *
 * @param array array ptr
 * @param type type to convert array
 * @param a index of the first element to switch
 * @param b index of the second element to switch
 * @internal
 */
#define swap_int(array, type, a, b)  \
  do {                               \
    type* conv_arr__ = (type*)array; \
    type temp__ = conv_arr__[a];     \
    conv_arr__[a] = conv_arr__[b];   \
    conv_arr__[b] = temp__;          \
  } while (0);

/**
 * Get pointer for specific element in void array
 * @param ptr array pointer
 * @param size size of one element
 * @param i index of element to be accessed
 * @return pointer to element
 */
char *elem_ptr(char *ptr, size_t size, size_t i) {
  return ptr + (size * i);
}
/**
 * Get pointer for specific byte of i-th element in void array
 * @param ptr array pointer
 * @param size size of one element
 * @param i index of element to be accessed
 * @return pointer to element
 * @internal
 */
char *elem_byte_ptr(char *ptr, size_t size, size_t i, size_t byte) {
  return elem_ptr(ptr, size, i) + byte;
}

void shell_sort(void *ptr, const size_t count, const size_t size, int (*comp)(const void *, const void *)) {
  char *array = ptr;
  for (size_t h = count / 2; h > 0; h /= 2) {
    for (size_t i = h; i < count; i++) {
      size_t j = i - h;
      while (comp(elem_ptr(array, size, j), elem_ptr(array, size, j + h)) > 0) {
        switch (size) {
          case sizeof(uint32_t):
            swap_int(array, uint32_t, j, j + h);
            break;
          case sizeof(uint64_t):
            swap_int(array, uint64_t, j, j + h);
            break;
          default:
            for (size_t k = 0; k < size; k++) {
              const char temp = *elem_byte_ptr(array, size, j, k);
              *elem_byte_ptr(ptr, size, j, k) = *elem_byte_ptr(ptr, size, j + h, k);
              *elem_byte_ptr(ptr, size, j + h, k) = temp;
            }
            break;
        }
        if (j < h) {
          break;
        }
        j -= h;
      }
    }
  }
}

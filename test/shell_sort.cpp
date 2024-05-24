//
// Created by Alex on 24.05.2024.
//
#include "gtest/gtest.h"

extern "C" {
#include "shell_sort.h"
}

int int_gt_cmp(const void* a, const void* b) {
  int arg1 = *(const int*)a;
  int arg2 = *(const int*)b;

  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

TEST(shellSort, testSimpleIntSort) {
  int a[10];
  for (int i = 0; i < 10; i++) {
    a[i] = 9 - i;
  }
  shell_sort(a, 10, sizeof(int), int_gt_cmp);
  for (int i = 0; i < 10; i++) {
    ASSERT_EQ(a[i], i);
  }
}
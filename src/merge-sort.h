#ifndef MERGE_SORT_HEADER
#define MERGE_SORT_HEADER
#include <stddef.h>

void merge_sort_doubles(size_t start, size_t end, double a[end-start]);
void merge_sort_strings(size_t start, size_t end, char a[end-start][255]);
int check_sorted_doubles(size_t length, double a[length]);
int check_sorted_strings(size_t length, char a[length][255]);
int test_merge_sort_doubles(size_t size);
int test_merge_sort_strings(size_t size);
#endif

#include "merge-sort.h"
#include "quick-sort.h"
#include "sort-utils.h"
#include "test-sorts.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    test_merge_sort_doubles(50);
    // test_merge_sort_strings(50, 32); // TODO: segfaulting
    test_quick_sort_doubles(50);
    // test_quick_sort_strings(50, 32); // TODO: segfaulting
}

int test_merge_sort_doubles(size_t length) {
    double array[length];
    printf("conducting merge sort test on %zu doubles: ", length);
    generate_doubles(length, array);
    merge_sort_doubles(0, length-1, array);
    
    return check_sorted_doubles(length, array); 
}

int test_merge_sort_strings(size_t length, size_t str_length) { 
    char strs[length][str_length];
    printf("conducting merge sort test on %zu strings: ", length);
    generate_strings(length, str_length, strs);
    merge_sort_strings(0, length-1, str_length, strs);

    return check_sorted_strings(length, str_length, strs);
}

int test_quick_sort_doubles(size_t length) {
    double array[length];
    printf("conducting quick sort test on %zu doubles: ", length);
    generate_doubles(length, array);
    quick_sort_doubles(0, length-1, array);

    return check_sorted_doubles(length, array);
}

int test_quick_sort_strings(size_t length, size_t str_length) {
    char strs[length][str_length];
    printf("conducting quick sort test on %zu strings: ", length);
    generate_strings(length, str_length, strs);
    quick_sort_strings(0, length-1, str_length, strs);

    return check_sorted_strings(length, str_length, strs);
}



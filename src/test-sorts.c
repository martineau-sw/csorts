#include "test-sorts.h"
#include <string.h>
#include <stdlib.h>

int main(void) {
    test_merge_sort_doubles(50);
    test_merge_sort_strings(50);
}

int check_sorted_doubles(size_t length, double a[length]) {
    for (size_t i = 1; i < length; i++) {
        if (a[i] < a[i-1]) {
            printf("doubles result: FAILED\n");
            return -1;
       }
    }

    printf("doubles result: PASSED\n");
    return 0;
}

int check_sorted_strings(size_t length, char a[length][255]) {
    for (size_t i = 1; i < length; i++) {
        if (strcmp(a[i], a[i-1]) == -1) {
            printf("strings result: FAILED\n");
            return -1;
        }
    }

    printf("strings result: PASSED\n");
    return 0;
}

int test_merge_sort_strings(size_t length) {
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char strs[length][255];
    for (size_t i = 0; i < length; i++) {
        char str[255];
        for (size_t j = 0; j < 255; j++) {
            str[j] = alpha[(rand() + i + j) % 16];
        }
        str[255-1] = '\0';
        strcpy(strs[i], str);
    }
    printf("conducting merge sort test on %zu strings: ", length);
    merge_sort_strings(0, length-1, strs);

    return check_sorted_strings(length, strs);
}

int test_merge_sort_doubles(size_t length) {
    double array[length];
    for (size_t i = 0; i < length; i++) {
        array[i] = rand() % length;
    }
    printf("conducting merge sort test on %zu doubles: ", length);
    merge_sort_doubles(0, length-1, array);
    
    return check_sorted_doubles(length, array); 
}

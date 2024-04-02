#include "./sort-utils.h"
#include <stdio.h>

void print_strings(char label[], size_t length, char a[length][255]) {
    printf("\nsize:%zu\n", length);
    for (size_t i = 0; i < length; ++i) {
        printf("%s[%zu] = %s\n",
                label,
                i,
                a[i]);
    }
}
void print_doubles(char label[], size_t length, double a[length]) {
    printf("\nsize:%zu\n", length);
    for (size_t i = 0; i < length; ++i) {
        printf("%s[%zu] = %f\n",
                label,
                i,
                a[i]);
    }
}

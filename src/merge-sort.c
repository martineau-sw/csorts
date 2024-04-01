#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int print_array(char label, size_t size, double array[size]);
void merge_sort(size_t start, size_t end, double a[end-start]);
int test_merge_sort();

int main(void) {
    int outcome = test_merge_sort();

    printf("\noutcome: %u\n", outcome);
    return outcome;
}

int print_array(char label, size_t size, double array[size]) {
    printf("\nsize:%zu\n", size);
    for (size_t i = 0; i < size; ++i) {
        printf("%c[%zu] = %f\n",
                label,
                i,
                array[i]);
    }

    return EXIT_SUCCESS;
}

int print_strs(char label, size_t size, char array[size][16]) {
    printf("\nsize:%zu\n", size);
    for (size_t i = 0; i < size; ++i) {
        printf("%c[%zu] = %s\n",
                label,
                i,
                array[i]);
    }

    return EXIT_SUCCESS;
}

void merge_sort(size_t start, size_t end, double array[end-start]) { 

    if(start == end) {
        return;
    }

    size_t mid = (start + end) / 2;
    merge_sort(start, mid, array);
    merge_sort(mid+1, end, array);
    
    size_t l_size = (mid-start)+1;
    size_t r_size = (end-mid);

    double l[l_size];
    double r[r_size];

    for (size_t i = 0; i < l_size; i++) {
        l[i] = array[start+i];
    }
    for (size_t i = 0; i < r_size; i++) {
        r[i] = array[mid+1+i];
    }

    size_t l_i = 0;
    size_t r_i = 0;
    size_t i = start;
    while (l_i < l_size && r_i < r_size) {
        if (l[l_i] <= r[r_i]) {
            array[i++] = l[l_i++];
        } else {
            array[i++] = r[r_i++];
        }
    }

    while (l_i < l_size) {
        array[i++] = l[l_i++];
    }
    while (r_i < r_size) {
        array[i++] = r[r_i++];
    }
}

void merge_sort_str(size_t start, size_t end, char array[end-start][16]) {
    if (start == end) {
        return;
    }

    size_t mid = (start+end)/2;
    merge_sort_str(start, mid, array);
    merge_sort_str(mid+1, end, array);
    
    size_t l_size = (mid-start)+1;
    size_t r_size = (end-mid);

    char l[l_size][16];
    char r[r_size][16];
    
    for (size_t i = 0; i < l_size; i++) {
        strcpy(l[i], array[start+i]);
    }
    for (size_t i = 0; i < r_size; i++) {
        strcpy(r[i], array[mid+1+i]);
    }

    size_t l_i = 0;
    size_t r_i = 0;
    size_t i = start;

    while (l_i < l_size && r_i < r_size) {
        if (strcmp(l[l_i], r[r_i]) < 1) {
            strcpy(array[i++], l[l_i++]);
        } else {
            strcpy(array[i++], r[r_i++]);
        }
    }

    while (l_i < l_size) {
        strcpy(array[i++], l[l_i++]);
    }
    while (r_i < r_size) {
        strcpy(array[i++], r[r_i++]);
    }
}

int check_sorted(size_t size, double array[size]) {
    for (size_t i = 1; i < size; i++) {
       if (array[i] < array[i-1]) {
           return EXIT_FAILURE;
       }
    }

    return EXIT_SUCCESS;
}

int check_sorted_str(size_t size, char array[size][16]) {
    for (size_t i = 1; i < size; i++) {
       if (strcmp(array[i], array[i-1]) == -1) {
           return EXIT_FAILURE;
       }
    }

    return EXIT_SUCCESS;
}

int test_merge_sort() {
    size_t const size = 10;
    size_t const length = 16;
    double array[size];
    for (size_t i = 0; i < size; i++) {
       array[i] = rand() % size;
    }
    printf("conducting merge sort test on %zu doubles\n", size);
    merge_sort(0, size-1, array);
    
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char strs[size][length];
    for (size_t i = 0; i < size; i++) {
        char str[length];
        for (size_t j = 0; j < length; j++) {
            str[j] = alpha[(rand() + i + j) % 16];
        }
        str[length-1] = '\0';
        printf("generated string %zu: %s\n", i, str);
        strcpy(strs[i], str);
    }
    printf("conducting merge sort test on %zu strings\n", size);
    print_strs('s', size, strs);
    merge_sort_str(0, size-1, strs);
    print_strs('s', size, strs);

    return check_sorted(size, array) + check_sorted_str(size, strs); 
}

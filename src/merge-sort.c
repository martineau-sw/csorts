#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int print_array(char label, size_t size, double array[size]);
void split_array(size_t start, size_t end, double a[end-start]);

int main(void) {
    size_t const size = 4;
    double a[size] = {
        [0] = 8,
        [1] = 7,
        [2] = 6,
        [3] = 5,
//        [4] = 4,
//        [5] = 3,
 //       [6] = 2,
  //      [7] = 1,
    };
    split_array(0, size-1, a);
    
    printf("\nfinal:");
    print_array('a', size, a);
    return EXIT_SUCCESS;
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

void split_array(size_t start, size_t end, double array[end-start]) { 

    size_t mid = (start + end) / 2;
    

    if(start == end) {
        return;
    }

    split_array(start, mid, array);
    split_array(mid+1, end, array);
    
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

    print_array('l', l_size, l);
    print_array('r', r_size, r);

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


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int print_array(size_t c, double array[c]);
void split_array(size_t start, size_t end, double a[end-start]);

int main(void) {
    size_t const size = 4;
    double a[size] = {
        [0] = 3,
        [1] = 1,
        [2] = 2,
        [3] = 4
    };
    print_array(size, a);
    split_array(0, size, a);
    print_array(size, a);
    return EXIT_SUCCESS;
}

int print_array(size_t c, double array[c]) {
    for (size_t i = 0; i < c; ++i) {
        printf("element %zu contains value %f\n",
                i,
                array[i]);
    }
    
    printf("\n");

    return EXIT_SUCCESS;
}

void split_array(size_t start, size_t end, double array[end-start]) { 
    printf("splitting array\tstart: %zu\tend: %zu\t", start, end);

    size_t midpoint = (start + end) / 2;
    
    printf("midpoint: %zu\n", midpoint);

    if(start == midpoint) {
        return;
    }

    split_array(start, midpoint, array);
    split_array(midpoint+1, end, array);
     
    for (size_t i = start; i < end; i += 2) {
        if (array[(start+i)/2] <= array[(midpoint+i)/2]) {
            array[i] = array[start+i/2];
            array[i+1] = array[(midpoint+i)/2];
        } else {
            array[i] = array[(midpoint+i)/2];
            array[i+1] = array[(start+i)/2];
        }
    }
    
}


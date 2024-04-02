
#include <stddef.h>
#include <stdlib.h>

void quick_sort(size_t low, size_t high, double array[]) {
    
    if (low > high || high < 0) {
        return;
    }

    size_t pivot_index = (high-low) / 2;
    
    double temp = array[pivot_index];
    array[pivot_index] = array[high-low];
    array[high-low] = temp;
    
    while (low <= high) {
        
        while (low < high-low && array[low] < array[high-low]) {
            low++;
        }

        while (high > 0 && array[high] > array[high-low]) {
            high--;
        }
    }

    temp = array[low];
    array[low] = array[high-low];
    array[high-low] = temp;

    quick_sort(0, high, array);
    quick_sort(low, high-low, array);
}

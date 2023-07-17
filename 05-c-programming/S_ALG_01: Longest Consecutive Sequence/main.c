#include <stdio.h>
#include "longest_consecutive_subsequence.h"

int main() {

    int32_t *input_array;
    uint8_t size;
    uint8_t lcs = 1;

    promptUser(&input_array, &size);
    printf("The input array is: ");
    printArray(input_array, size);

    /* Sorting the input array. */
    insertionSort(input_array, size);

    printf("The array after being sorted: ");
    printArray(input_array, size);

    /* Calculate the LCS. */
    lcsGetSize(input_array, size,&lcs);

    printf("The longest consecutive sequence is: ");
    printf("%u", lcs);

    return 0;
}

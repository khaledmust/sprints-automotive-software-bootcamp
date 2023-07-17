#include "longest_consecutive_subsequence.h"

/**
 * @brief Performs insertion sorting algorithm.
 *
 * Sorts the array in ascending order.
 *
 * @param[in,out] array Address of the array to be sorted.
 * @param[in] arraySize Size of the input array.
 * @return -1 Array is empty.
 * @return -2 Array size is 0 or >10.
 * @return 0 Sorting is done without errors.
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize) {
    for (int i = 1; i < arraySize; i++) {
        int current_element = array[i];
        int sorted_array_index = i - 1;
        while (sorted_array_index >= 0 && array[sorted_array_index] > current_element) {
            array[sorted_array_index + 1] = array[sorted_array_index];
            sorted_array_index--;
        }
        array[sorted_array_index + 1] = current_element;
    }
}

/**
 * @brief Prints all the elements of input array.
 * @param array[in] Reference to an array of integers to be printed.
 * @param arraySize[in] Size of the reference array.
 */
void printArray(int32_t *array, uint8_t arraySize) {
    int i;
    for (i = 0; i < arraySize; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}


/**
 * @brief Prompts the user to enter the array size and then allocates the array.
 * @param array[out] Reference to a reference of an array.
 * @param arraySize[out] Reference to the size of the array.
 * @return -1 Array is empty.
 * @return -2 Array size is 0 or >10.
 * @return 0 Prompting and allocation is done without errors.
 */
int8_t promptUser(int32_t **array, uint8_t *arraySize) {
    /* Get the size of the array. */
    int tmp_user_input;
    printf("Enter the array size: ");
    scanf("%d", &tmp_user_input);
    *arraySize = tmp_user_input;
    if (*arraySize == 0 || *arraySize > 10) {
        printf("Error! Array size could only be greater than 0 and less than 10.\n");
        return -2;
    }

    /* Allocating the required array on the heap. */
    *array = (int32_t*) malloc(sizeof (uint32_t) * (*arraySize));

    /* Get the content of the array. */
    printf("Enter your array: ");
    for (uint8_t i = 0; i < *arraySize; i++) {
        scanf("%d", (*array + i));

        if (array[0] == '\n') {
            printf("Error! Element can't be empty.\n");
            return -1;
        }
    }
    return 0;
}

/**\
 * @brief Takes a reference to an array and calculates the longest consecutive subsequence.
 * @param array[in] Reference the input array.
 * @param arraySize[in] Size of the array.
 * @param sizeofLCS[out] Reference to store the longest consecutive subsequence.
 * @return -1 The array is empty
 * @return -2 The array size is 0 or >10
 * @return -3 There is no LCS,
 */
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS) {
    if (arraySize == NULL) {
        return -1;
    } else if (arraySize == 0 || arraySize > 10) {
        return -2;
    } else {
        uint8_t length = 1;
        /* Iterating over every element and comparing it with the one after, if it's equal then the two elements
         * are considered consecutive.
         */
        for (int i = 0; i < arraySize; i++) {
            if (array[i] == array[i + 1]) {
                continue;
            } else if (i > 0 && array[i] == array[i - 1] + 1) {
                length++;
            } else {
                length = 1;
            }
            /* Preserve the current consecutive length. */
            if (*sizeofLCS < length) {
                *sizeofLCS = length;
            }
        }
        /* There is no consecutive elements. */
        if (*sizeofLCS == 1) {
            return -3;
        } else {
            return 0;
        }
    }
}
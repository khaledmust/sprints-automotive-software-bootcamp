#ifndef S_ALG_LONGEST_CONSECUTIVE_SUBSEQUENCE_H
#define S_ALG_LONGEST_CONSECUTIVE_SUBSEQUENCE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Performs insertion sorting algorithm.
 * @param[in,out] array Address of the array to be sorted.
 * @param[in] arraySize Size of the input array.
 * @return -1 Array is empty.
 * @return -2 Array size is 0 or >10.
 * @return 0 Sorting is done without errors.
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize);

/**
 * @brief Prints all the elements of input array.
 * @param array[in] Reference to an array of integers to be printed.
 * @param arraySize[in] Size of the reference array.
 */
void printArray(int32_t *array, uint8_t arraySize);

/**
 * @brief Prompts the user to enter the array size and then allocates the array.
 * @param array[out] Reference to a reference of an array.
 * @param arraySize[out] Reference to the size of the array.
 * @return -1 Array is empty.
 * @return -2 Array size is 0 or >10.
 * @return 0 Prompting and allocation is done without errors.
 */
int8_t promptUser(int32_t **array, uint8_t *arraySize);

/**\
 * @brief Takes a reference to an array and calculates the longest consecutive subsequence.
 * @param array[in] Reference the input array.
 * @param arraySize[in] Size of the array.
 * @param sizeofLCS[out] Reference to store the longest consecutive subsequence.
 * @return -1 The array is empty
 * @return -2 The array size is 0 or >10
 * @return -3 There is no LCS,
 */
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);

#endif //S_ALG_LONGEST_CONSECUTIVE_SUBSEQUENCE_H

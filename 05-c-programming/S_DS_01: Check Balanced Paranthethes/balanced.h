#ifndef S_DS_01_CHECK_BALANCED_PARENTHESIS_BALANCED_H
#define S_DS_01_CHECK_BALANCED_PARENTHESIS_BALANCED_H
#include "stack.h"
#include "stdint.h"
#include <stdio.h>

/* Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of parentheses is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
int8_t isBalancedParanthethes(uint8_t *expression);

#endif //S_DS_01_CHECK_BALANCED_PARENTHESIS_BALANCED_H

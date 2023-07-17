#include "balanced.h"


/* Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of parentheses is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
int8_t isBalancedParanthethes(uint8_t *expression) {
    ST_stack_t myStack;
    uint8_t tmp;
    uint8_t flag = 0;
    createEmptyStack(&myStack);
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '{' || expression[i] == '}' || expression[i] == '(' || expression[i] == ')') {
            push(&myStack, expression[i]);
            flag = 1;
        }
        if (myStack.top > 0) {
            if (myStack.elements[myStack.top] == '}' && myStack.elements[--myStack.top] == '{') {
                pop(&myStack, &tmp);
                pop(&myStack, &tmp);
            } else if (myStack.elements[myStack.top] == ')' && myStack.elements[--myStack.top] == '(') {
                myStack.top++;
                pop(&myStack, &tmp);
                pop(&myStack, &tmp);
            }
        }
    }
    if (flag != 1) {
        return -2;
    }
    if (myStack.top == -1) {
        return 0;
    }
    else
    {
        return -1;
    }
}
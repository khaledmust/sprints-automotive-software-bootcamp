#include <stdio.h>
//#include "stack.h"
#include "balanced.h"

int main() {
    /* Uncomment to test the stack implementation. */
//    __testStack();

    uint8_t user_string[50];
    printf("Enter the expression to want to check: ");
    scanf("%s", user_string);

    int8_t expression_state = isBalancedParanthethes(user_string);
    if (expression_state == 0) {
        printf("The expression is balanced.\n");
    } else if (expression_state == -1) {
        printf("The expression is not balanced.\n");
    } else if (expression_state == -2) {
        printf("The expression doesn't have any parentheses.");
    }

    return 0;
}

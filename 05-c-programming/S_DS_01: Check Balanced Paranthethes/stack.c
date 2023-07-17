#include "stack.h"

/* Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 * Return:
 * - Nothing to return
 */
void createEmptyStack(ST_stack_t *stack) {
    memset(stack -> elements, 0, sizeof(uint8_t) * STACK_SIZE);
    stack -> top = -1;

}

/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
int8_t push(ST_stack_t *stack, uint8_t data) {
    /* Stack is full. */
    if (stack -> top == STACK_SIZE -1) {
        return -1;
    } else {
        stack -> elements[++(stack -> top)] = data;
        return 0;
    }
}

/* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t pop(ST_stack_t *stack, uint8_t *data) {
    /* Stack is empty. */
    if (stack -> top == -1) {
        return -2;
    } else {
        *data = stack -> elements[stack -> top];
        stack -> top--;
        return 0;
    }
}

/* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t printStack(ST_stack_t *stack) {
    printf("The content of the stack is:\n");
    for (uint8_t index = 0; index <= stack -> top; index++) {
        printf("%d  ", stack -> elements[index]);
    }
    printf("\n");
    /* Stack is full. */
    if (stack -> top == STACK_SIZE - 1) {
        return -1;
        /* Stack is empty. */
    } else if (stack -> top == -1) {
        return -2;
    } else {
        return 0;
    }
}

/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData) {
    if (stack -> top == -1) {
        return -2;
    } else {
        * topData = stack -> elements[stack -> top];
        return 0;
    }
}

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
int8_t isFull(ST_stack_t *stack) {
    if (stack -> top == STACK_SIZE -1) {
        return -1;
    } else {
        return 0;
    }
}

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t *stack) {
    if (stack -> top == -1) {
        return -2;
    } else {
        return 0;
    }
}

/* Description:
 * - This function performs a unit test on the stack.
 * 1. Create an empty stack
 * 2. Push 5 different characters to the stack
 * 3. Print all stack data
 * 4. Pop one character from the stack
 * 5. Print the stack's top
 * 6. Print all stack data
 * 7. Push another 7 different characters to the stack
 * 8. Print the stack's top
 * 9. Print all stack data
 * 10. Pop 4 characters from the stack
 * 11. Print the stack's top
 * 12. Print all stack data
 * 13. Pop 7 more times from the stack
 * 14. Print the stack's top
 * 15. Print all stack data
 */
void __testStack(void) {
    uint8_t tmp;

    /* 1. Create an empty stack */
    printf("1. Creating an empty stack.\n");
    ST_stack_t myStack;
    createEmptyStack(&myStack);

    /* 2. Push 5 different characters to the stack */
    printf("2. Pushing five different elements.\n");
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);

    /* 3. Print all stack data */
    printf("3. Printing all the content of the stack.\n");
    printStack(&myStack);

    /* 4. Pop one character from the stack */
    printf("4. Popping one element from the stack.\n");
    pop(&myStack, &tmp);

    /* 5. Print the stack's top */
    getStackTop(&myStack, &tmp);
    printf("5. Current stack top: %d.\n", tmp);

    /* 6. Print all stack data */
    printf("6. Printing all the content of the stack.\n");
    printStack(&myStack);

    /* 7. Push another 7 different characters to the stack */
    printf("7. Pushing another seven elements.\n");
    push(&myStack, 60);
    push(&myStack, 70);
    push(&myStack, 80);
    push(&myStack, 90);
    push(&myStack, 100);
    push(&myStack, 110);
    push(&myStack, 120);

    /* 8. Print the stack's top */
    getStackTop(&myStack, &tmp);
    printf("8. Current stack top: %d.\n", tmp);

    /* 9. Print all stack data */
    printf("9. Printing all the content of the stack.\n");
    printStack(&myStack);

    /* 10. Pop 4 characters from the stack */
    printf("10. Popping 4 elements from the stack.\n");
    pop(&myStack, &tmp);
    pop(&myStack, &tmp);
    pop(&myStack, &tmp);
    pop(&myStack, &tmp);

    /* 11. Print the stack's top  */
    getStackTop(&myStack, &tmp);
    printf("11. Current stack top: %d.\n", tmp);

    /* 12. Print all stack data */
    printf("12. Printing all the content of the stack.\n");
    printStack(&myStack);

    /* 13. Pop 7 more times from the stack */
    printf("13. Popping 7 elements from the stack.\n");
    pop(&myStack, &tmp);
    pop(&myStack, &tmp);
    pop(&myStack, &tmp);
    pop(&myStack, &tmp);
    pop(&myStack, &tmp);
    pop(&myStack, &tmp);
    pop(&myStack, &tmp);

    /* 14. Print the stack's top  */
    getStackTop(&myStack, &tmp);
    printf("14. Current stack top: %d.\n", tmp);

    /* 15. Print all stack data */
    printf("15. Printing all the content of the stack.\n");
    printStack(&myStack);
}
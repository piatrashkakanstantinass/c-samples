#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *p;
    int size;
} Stack;

void initStack(Stack *stack) {
    stack->p = NULL;
    stack->size = 0;
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->size; ++i)
        printf("%d ", stack->p[i]);
}

int getStackSize(Stack *stack) {
    return stack->size;
}

void push(Stack *stack, int value) {
    int *new_p = (int *)realloc(stack->p, (stack->size + 1) * sizeof(int));
    if (new_p) {
        stack->p = new_p;
        stack->p[stack->size++] = value;
    }
}

int top(Stack *stack) {
    return stack->size ? stack->p[stack->size - 1] : 0;
}

void destroyStack(Stack *stack) {
    free(stack->p);
    initStack(stack);
}

int pop(Stack *stack) {
    int value = top(stack);
    if (stack->size > 1) {
        int *new_p = (int *)realloc(stack->p, (stack->size - 1) * sizeof(int));
        if (new_p) {
            stack->p = new_p;
            --stack->size;
        }
    }
    else
        destroyStack(stack);
    return value;
}

int main(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    top(&stack);
    top(&stack);
    printStack(&stack);
    printf("\n%d %d\n", pop(&stack), getStackSize(&stack));
    printStack(&stack);
    destroyStack(&stack);
    return 0;
}
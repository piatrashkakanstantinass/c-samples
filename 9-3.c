#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point *p;
    int size;
} Stack;

Point createPoint(double x, double y) {
    Point p = {x, y};
    return p;
}

void printPoint(Point p) {
    printf("(%g, %g)", p.x, p.y);
}

double getDistance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initStack(Stack *stack) {
    stack->p = NULL;
    stack->size = 0;
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->size; ++i) {
        printPoint(stack->p[i]);
        printf(" distance from (0, 0) = %g\n", getDistance(stack->p[i], createPoint(0, 0)));
    }
}

int getStackSize(Stack *stack) {
    return stack->size;
}

void push(Stack *stack, Point value) {
    Point *new_p = (Point *)realloc(stack->p, (stack->size + 1) * sizeof(Point));
    if (new_p) {
        stack->p = new_p;
        stack->p[stack->size++] = value;
    }
}

Point top(Stack *stack) {
    return stack->size ? stack->p[stack->size - 1] : createPoint(0, 0);
}

void destroyStack(Stack *stack) {
    free(stack->p);
    initStack(stack);
}

Point pop(Stack *stack) {
    Point value = top(stack);
    if (stack->size > 1) {
        Point *new_p = (Point *)realloc(stack->p, (stack->size - 1) * sizeof(Point));
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
    Stack s;
    initStack(&s);
    push(&s, createPoint(1, 1));
    push(&s, createPoint(2, 1));
    push(&s, createPoint(1, 2));
    push(&s, createPoint(2, 2));
    push(&s, createPoint(6, 8));
    printStack(&s);
    return 0;
}
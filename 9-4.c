#include <stdlib.h>
#include <stdio.h>

typedef struct {
    double x, y;
} Point;

typedef struct List {
    Point value;
    struct List *next;
} List;

void printPoint(Point p) {
    printf("(%g, %g)", p.x, p.y);
}

Point createPoint(double x, double y) {
    Point p = {x, y};
    return p;
}

List *createList(Point value) {
    List *list = (List *)malloc(sizeof(List));
    if (list) {
        list->value = value;
        list->next = NULL;
    }
    return list;
}

void printList(List *list) {
    if (list) {
        printPoint(list->value);
        if (list->next) {
            printf(" ");
            printList(list->next);
        }
    }
}

int getListSize(List *list) {
    int count = 0;
    while (list) {
        ++count;
        list = list->next;
    }
    return count;
}

void insertElement(List **list, Point value) {
    List *new_list = createList(value);
    if (new_list) {
        new_list->next = *list;
        *list = new_list;
    }
}

Point getElement(List *list) {
    return list ? list->value : createPoint(0, 0);
}

Point deleteElement(List **list) {
    Point element = getElement(*list);
    if (*list) {
        List *next = (*list)->next;
        free(*list);
        *list = next;
    }
    return element;
}

void destroyList(List **list) {
    while (*list)
        deleteElement(list);
}

int main(void) {
    List *l = createList(createPoint(0, 0));
    insertElement(&l, createPoint(1, 1));
    insertElement(&l, createPoint(2, 2));
    insertElement(&l, createPoint(3, 3));
    insertElement(&l, createPoint(4, 4));
    printList(l);
    printf("\n");
    printPoint(getElement(l));
    printf(" %d\n", getListSize(l));
    printPoint(deleteElement(&l));
    printf("\n");
    printList(l);
    printf("\n");
    destroyList(&l);
    printList(NULL);
    return 0;
}
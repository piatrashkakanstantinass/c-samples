#include <stdlib.h>
#include <stdio.h>

struct Block {
    void *start;
    size_t size;
};

struct Block *block_ptr = NULL;
size_t block_count = 0;

void defragmentMemory() {
    for (size_t i = 0; i < block_count; ++i)
        if (!block_ptr[i].start)
            block_ptr[i] = block_ptr[--block_count];
}

size_t getMallocSize() {
    size_t total = 0;
    for (size_t i = 0; i < block_count; ++i)
        total += block_ptr[i].size;
    return total;
}

void freeAll() {
    for (size_t i = 0; i < block_count; ++i)
        free(block_ptr[i].start);
    free(block_ptr);
    block_ptr = NULL;
    block_count = 0;
}

void *myRealloc(void *ptr, size_t size) {
    struct Block *matched_block = NULL;
    for (size_t i = 0; i < block_count; ++i)
        if (block_ptr[i].start == ptr) {
            matched_block = block_ptr + i;
            break;
        }
    if (!matched_block) {
        struct Block *new_block_ptr = (struct Block *) realloc(block_ptr, block_count + 1);
        if (!new_block_ptr) {
            return NULL;
        }
        block_ptr = new_block_ptr;
        matched_block = block_ptr + block_count++;
        matched_block->start = NULL;
        matched_block->size = 0;
    }
    void *new_ptr = realloc(ptr, size);
    if (new_ptr) {
        matched_block->start = new_ptr;
        matched_block->size = size;
    }
    return new_ptr;
}

void *myMalloc(size_t size) {
    return myRealloc(NULL, size);
}

void *myCalloc(size_t count, size_t size) {
    void *ptr = myRealloc(NULL, count * size);
    if (ptr) {
        for (size_t i = 0; i < count * size; ++i)
            ((char *)ptr)[i] = 0;
    }
    return ptr;
}

void myFree(void *ptr) {
    for (size_t i = 0; i < block_count; ++i)
        if (block_ptr[i].start == ptr) {
            block_ptr[i].start = NULL;
            block_ptr[i].size = 0;
        }
    free(ptr);
    defragmentMemory();
}

int main(void ) {
    char *name = (char *) myMalloc(8);
    name[0] = 'h';
    name[1] = 'i';
    name[2] = '\0';
    myRealloc(name, 3);
    printf("%s\n", name);
    printf("%zu\n", block_count);
    printf("%p\n", block_ptr);
    myFree(name);
    myMalloc(3);
    freeAll();
    return 0;
}
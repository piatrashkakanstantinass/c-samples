#include <stddef.h>
#include <assert.h>

size_t myStrlen(const char *str) {
    unsigned len = 0;
    while (*(str++))
        ++len;
    return len;
}

int main(void) {
    assert(myStrlen("hello world") == 11);
    assert(myStrlen("") == 0);
    return 0;
}
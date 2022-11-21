#include <assert.h>
#include <stddef.h>

void* myMemchr(void* ptr, int ch, size_t count) {
    if (count == 0)
        return NULL;
    while (*(unsigned char *)ptr != (unsigned char)ch && --count)
        ++ptr;
    return *(unsigned char *)ptr == (unsigned char)ch ? ptr : NULL;
}

int main(void) {
    unsigned char buff[] = {0, 1, 2, 3, 4, 5, 4, 3, 6, 9, 10, 12, 15, 230};
    assert(myMemchr(buff, 6, 10) == buff + 8);
    assert(myMemchr(buff, 6, 8) == NULL);
    assert(myMemchr(buff, 0, 0) == NULL);
    assert(myMemchr(buff, 0, 1) == buff);
    return 0;
}
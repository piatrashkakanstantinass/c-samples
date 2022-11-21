#include <assert.h>
#include <stddef.h>
#include <string.h>

size_t myStrcspn(const char *dest, const char *src) {
    size_t length = 0;
    while (!strchr(src, dest[length]))
        ++length;
    return length;
}

int main(void) {
    assert(myStrcspn("hello", "kol") == 2);
    assert(myStrcspn("hello", "GKHL") == 5);
    assert(myStrcspn("hello", "hk") == 0);
    return 0;
}
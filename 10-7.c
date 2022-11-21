#include <assert.h>
#include <string.h>
#include <stdlib.h>

char* myStrpbrk(char* dest, const char* breakset) {
    while (*dest && !strchr(breakset, *dest))
        ++dest;
    return *dest ? dest : NULL;
}

int main(void) {
    char buff[] = "hello,k#\n";
    assert(myStrpbrk(buff, "#\n,") == buff + 5);
    assert(myStrpbrk(buff, "!FDAGGDFDGADFJFDLJ$") == NULL);
    return 0;
}
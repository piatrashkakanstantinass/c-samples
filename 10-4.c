#include <assert.h>
#include <stdlib.h>

char *myStrchr(char *str, int ch) {
    while (*str != ch && *str)
        ++str;
    return *str == ch ? str : NULL;
}

int main(void) {
    char buff[100] = "hello";
    assert(myStrchr(buff, 'l') == buff + 2);
    assert(myStrchr("world", 'B') == NULL);
    assert(myStrchr(buff, '\0') == buff + 5);
    return 0;
}
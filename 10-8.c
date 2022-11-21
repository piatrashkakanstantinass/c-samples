#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *myStrtok(char *str, const char *delim) {
    static char *p;
    if (str)
        p = str;
    if (!p)
        return NULL;    
    while (*p && strchr(delim, *p))
        ++p;
    if (!*p) {
        p = NULL;
        return p;
    }
    str = p;
    while (*p && !strchr(delim, *p))
        ++p;
    if (!*p) {
        p = NULL;
        return str;
    }
    *p = '\0';
    ++p;
    return str;
}

int main(void) {
    char buff[] = "hello;world,radavicus and  ,;  ,; ko ;,";
    assert(myStrtok(NULL, ";, ") == NULL);
    assert(myStrtok(buff, ";, ") == buff && buff[5] == '\0');
    assert(myStrtok(NULL, ";, ") == buff + 6 && buff[11] == '\0');
    assert(myStrtok(NULL, ";, ") == buff + 12 && buff[21] == '\0');
    assert(myStrtok(NULL, ";, ") == buff + 22 && buff[25] == '\0');
    assert(myStrtok(NULL, ";, ") == buff + 34 && buff[36] == '\0');
    assert(myStrtok(NULL, ";, ") == NULL);
    assert(myStrtok(NULL, ";, ") == NULL);
    return 0;
}
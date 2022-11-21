#include <assert.h>

int myStrcmp(const char *lhs, const char *rhs) {
    for (; *lhs == *rhs && *lhs; ++lhs, ++rhs)
        ;
    return *lhs - *rhs;
}

int main(void) {
    assert(myStrcmp("equal", "equal") == 0);
    assert(myStrcmp("", "") == 0);
    assert(myStrcmp("abbbb", "baaaaaaaa") < 0);
    assert(myStrcmp("dbca", "abb") > 0);
    return 0;
}
#include <stddef.h>
#include <assert.h>

int myStrncmp(const char *lhs, const char *rhs, size_t count) {
    if (count == 0)
        return 0;
    for (; *lhs == *rhs && *lhs && --count; ++lhs, ++rhs)
        ;
    return *lhs - *rhs;
}

int main(void) {
    assert(myStrncmp("equal", "equal", 100) == 0);
    assert(myStrncmp("", "", 0) == 0);
    assert(myStrncmp("abbbb", "baaaaaaaa", 1) < 0);
    assert(myStrncmp("dbca", "abb", 2) > 0);
    assert(myStrncmp("abcDEF", "abcABC", 3) == 0);
    assert(myStrncmp("abcDEF", "abcABC", 10) > 0);
    assert(myStrncmp("abc", "def", 0) == 0);
    return 0;
}
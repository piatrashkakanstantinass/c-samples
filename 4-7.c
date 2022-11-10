#include <stdio.h>

typedef signed char sc;
typedef unsigned char usc;
typedef unsigned short us;
typedef unsigned long ul;


#define CALCULATE_BOUNDARIES(type, type_str, specifier) \
    type type##_max, type##_min; \
    type##_max = type##_min = 0; \
    while (++type##_min > type##_max) \
        ++type##_max; \
    printf("%s max = %" specifier ", %s min = %" specifier "\n", type_str, type##_max, type_str, type##_min);

int main(void) {
    printf("Si programa randa sveikuju c kalbos tipu rezius\n");
    CALCULATE_BOUNDARIES(sc, "signed char", "d")
    CALCULATE_BOUNDARIES(usc, "unsigned char", "d")
    CALCULATE_BOUNDARIES(short, "signed short", "d")
    CALCULATE_BOUNDARIES(us, "unsigned short", "d")
    CALCULATE_BOUNDARIES(int, "signed int", "d")
    CALCULATE_BOUNDARIES(unsigned, "unsigned int", "u")
    CALCULATE_BOUNDARIES(long, "signed long", "ld")
    CALCULATE_BOUNDARIES(ul, "unsigned long", "lu")
    return 0;
}
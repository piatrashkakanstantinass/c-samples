#include <stdio.h>
#include <ctype.h>

int getPositiveNumber(char *msg) {
    int n, flag;
    char c;
    while (printf("%s", msg)) {
        if ((flag = scanf("%9d%c", &n, &c)) != 2 || c != '\n') {
            if (flag == EOF)
                return -1;
            scanf("%*[^\n]");
        }
        else if (n > 0)
            break;
    }
    return n;
}

int main(void) {
    printf("Got number: %d\n", getPositiveNumber("Number: "));
    return 0;
}
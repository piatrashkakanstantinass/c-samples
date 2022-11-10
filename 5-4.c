#include <stdio.h>

#define CAPACITY 1000

int isprime(int n) {
    if (n == 1) return 0;
    for (int i = 2; i < n; ++i)
        if (n % i == 0) return 0;
    return 1;
}

int main(void) {
    printf("Si programa isimena vedamus teigiamus skaicius iki pirmos neteigiamos reiksmes ir atspausdina ivestus pirminius skaicius\n");
    int m[CAPACITY];
    int size = 0;

    while (size < CAPACITY) {
        char c;
        while (printf("Iveskite skaiciu: "), scanf("%d%c", &m[size], &c) != 2 || c != '\n') {
            printf("Netinkama ivestis\n");
            scanf("%*[^\n]");
        }
        if (m[size] <= 0) break;
        if (isprime(m[size])) {
            int duplicate = 0;
            for (int i = 0; i < size; ++i)
                if (m[i] == m[size]) {
                    duplicate = 1;
                    break;
                }
            if (!duplicate)
                ++size;
        }
    }

    printf("Duomenys ivesti sekmingai\n");

    printf("Ivesti pirminiai skaiciai:");
    for (int i = 0; i < size; ++i)
        printf(" %d", m[i]);
    printf("\n");

    return 0;
}
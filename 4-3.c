#include <stdio.h>

int main(void) {
    printf("Si programa atspausdina c-taji fibonaci sekos nari, kad f0=a, f1=b\n");
    printf("Iveskite 3 neneigiamus sveikuosius skaicius (a, b, c): ");
    int a, b, c;
    if (scanf("%d%d%d", &a, &b, &c) != 3 || a < 0 || b < 0 || c < 0) {
        printf("Netinkama ivestis\n");
        return 1;
    }
    printf("Duomenys nuskaityti sekmingai\n");

    printf("c-tasis narys: ");

    int temp, prev = a, curr = b;
    if (c == 0)
        printf("%d", prev);
    else {
        for (int i = 1; i < c; ++i) {
            temp = prev;
            prev = curr;
            curr += temp;
        }
        printf("%d", curr);
    }

    printf("\n");
    return 0;
}
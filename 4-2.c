#include <stdio.h>

int main(void) {
    printf("Si programa atspausdina visus teigiamus sveikus skaicius is intervalo (a;b] kurie dalinasi is c su liekana 1\n");
    printf("Iveskite tris sveikuosius skaicius (a, b, c): ");
    int a, b, c;
    if (scanf("%d%d%d", &a, &b, &c) != 3) {
        printf("Netinkama ivestis\n");
        return 1;
    }
    if (c == 0) {
        printf("Dalyba is nulio negalima\n");
        return 1;
    }
    printf("Duomenys nuskaityti sekmingai\n");
    printf("Gauta skaiciu seka:");

    while (++a < b) {
        if (a > 0 && a % c == 1)
            printf(" %d", a);
    }
    printf("\n");
    return 0;
}
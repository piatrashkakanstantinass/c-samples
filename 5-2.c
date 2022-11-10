#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACITY 1000

int main(void) {
    srand(time(NULL));
    int m[CAPACITY];
    int a, b, c;

    printf("Si programa uzpildo masyva c atsitiktiniais skaiciais is intervalo [a;b]\n");
    printf("Iveskite 3 sveikus skaicius a, b, c (c turi buti intervale [0;%d]). Tarp skaiciu dekite tarpa: ", CAPACITY);

    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Netinkama ivestis\n");
        return 1;
    }
    if (c < 0 || c > CAPACITY) {
        printf("Netinkama c reiksme (Turi buti intervale [0;%d]\n", CAPACITY);
        return 1;
    }
    if (a > b || b - a > RAND_MAX) {
        printf("Netinkamos a ir b reiksmes (Gali buti, kad neimanoma sugeneruoti atsitiktinio skaiciaus is didelio intervalo)\n");
        return 1;
    }
    printf("Duomenys sekmingai nuskaityti\n");

    for (int i = 0; i < c; ++i)
        m[i] = rand()%(b-a+1) + a;
    
    printf("Sugeneruotas masyvas:");
    for (int i = 0; i < c; ++i)
        printf(" %d", m[i]);
    printf("\n");

    return 0;
}
#include <stdio.h>

int main(void) {
    printf("Si programa randa sekos suma, vidurki, minimalia bei maksimalia reiksmes\n");
    printf("Iveskite sekos nariu skaciu n: ");
    int n;
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Netinkama ivestis\n");
        return 1;
    }
    printf("Iveskite seka: ");
    double num, sum = 0, max, min;
    for (int i = 0; i < n; ++i) {
        if (scanf("%lf", &num) != 1) {
            printf("Netinkama isvestis\n");
            return 1;
        }
        if (i == 0)
            max = min = num;
        sum += num;
        if (num > max)
            max = num;
        else if (num < min)
            min = num; 
    }
    printf("Duomenys nuskaityti sekmingai\n");

    printf("Suma = %f, vidurkis = %f, min = %f, max = %f\n", sum, sum/n, min, max);
    return 0;
}
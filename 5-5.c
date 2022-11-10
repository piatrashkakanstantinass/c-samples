#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1000

int enough_digits(int digit_count[], int n) {
    int n_digit_count[10] = {0};
    while (n / 10) {
        ++n_digit_count[abs(n % 10)];
        n /= 10;
    }
    for (int i = 0; i < 10; ++i)
        if (n_digit_count[i] > digit_count[i])
            return 0;
    return 1;
}

int main(void) {
    printf("Si programa patikrina ar is skaiciaus x skaitmenu galima sudaryti visus masyvo elementus\n");

    int x, n;
    int m[CAPACITY];
    int digit_count[10] = {0};

    printf("Iveskite skaicius x ir n, kur n yra masyvo elementu skaicius (n > 0): ");
    if (scanf("%d %d", &x, &n) != 2 || n <= 0) {
        printf("Netinkama ivestis\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        char c;
        while (printf("Iveskite %d-a masyvo elementa: ", i + 1), scanf("%d%c", &m[i], &c) != 2 || c != '\n') {
            printf("Netinkama ivestis\n");
            scanf("%*[^\n]");
        }
    }
    printf("Duomenys nuskaityti sekmingai\n");
    while (x / 10) {
        ++digit_count[abs(x % 10)];
        x /= 10;
    }
    for (int i = 0; i < n; ++i)
        if (!enough_digits(digit_count, m[i])) {
            printf("Is skaiciaus x skaitmenu negalima sudaryti visu masyvo elemntu\n");
            return 0;
        }
    printf("Is skaiciaus x skaitmenu galima sudaryti visus masyvo elementus\n");
    return 0;
}
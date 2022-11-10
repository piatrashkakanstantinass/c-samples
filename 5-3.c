#include <stdio.h>

#define CAPACITY 1000

int main(void) {
    printf("Si programa nuskaito teigiamu skaiciu masyva ir randa visas skaiciu poras, kuriu sandauga lygi s\n");
    printf("Printf iveskite tarpu atskirtus teigiamus skaicius s ir n (n - masyvo elementu skaicius, n <= %d): ", CAPACITY);

    unsigned s, n;
    unsigned m[CAPACITY];
    char c;

    if (scanf("%d %d%c", &s, &n, &c) != 3 || c != '\n' || s <= 0 || n <= 0 || n > CAPACITY) {
        printf("Netinkama ivestis arba virsyta masyvo talpa\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        while (printf("Iveskite %d-aji teigiama masyvo elementa: ", i + 1),
        scanf("%d%c", &m[i], &c) != 2 || c != '\n' || m[i] <= 0) {
            printf("Netinkama ivestis. Bandykite dar karta.\n");
            scanf("%*[^\n]");
        }
    }

    printf("Duomenys nuskaityti sekmingai\nRastos skaiciu poros:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (m[i] * m[j] == s)
                printf("m[%d](%d) * m[%d](%d) = %d\n", i, m[i], j, m[j], s);

        }
    }

    return 0;
}
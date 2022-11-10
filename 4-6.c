#include <stdio.h>

int main(void) {
    printf("Si programa randa daugiausia skaitmenu turinti skaiciu is teigiamu skaiciu sekos\n");
    printf("Iveskite seka (jos pabaiga zymima pirmu neteigiamu skaiciu): ");
    int num = 1, max_digits = 1, got_value = 0;
    while (num > 0) {
        if (scanf("%d", &num) != 1) {
            printf("Netinkama ivestis\n");
            return 1;
        }
        if (num > 0)
            got_value = 1;
        if (num > max_digits)
            max_digits = num;
    }
    if (!got_value)
        printf("Neivedete ne vieno teigiamo skaiciaus\n");
    else
        printf("Duomenys nuskaityti sekmingai\nDaugiausia skaitmenu turi skaicius %d\n", max_digits);
    return 0;
}
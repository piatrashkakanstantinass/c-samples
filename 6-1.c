#include <stdio.h>

int main(void) {
    printf("Si programa apskaiciuoja teigiamo skaiciaus faktoriala (skaicius negali susideti is daugiau nei 9 simboliu)\n");
    int x;
    char c;
    while (printf("Iveskite teigiama sveika skaiciu ir spauskite enter: ")) {
        int args_read = scanf("%9d%c", &x, &c);
        int flush = 0;
        switch (args_read) {
            case EOF:
                printf("Pasiekta failo pabaiga. Baigiamas darbas.\n");
                return 1;

            case 0:
                printf("Neivedete sveiko skaiciaus\n");
                flush = 1;
                break;

            default:
                if (c != '\n') {
                    printf("Ivedus skaicius turite spausti enter (arba virsijote simboliu skaiciu)\n");
                    flush = 1;
                }
                else if (x < 1) {
                    printf("Ivedete neteigiama skaiciu\n");
                    flush = 1;
                }
                break;
        }

        if (flush) {
            if (args_read != 2 || c != '\n')
                scanf("%*[^\n]");
        }
        else
            break;
    }
    printf("Duomenys nuskaityti sekmingai\n");

    unsigned fact = 1;
    while (x)
        fact *= x--;

    FILE *fp = fopen("out.txt", "w");
    if (fp == NULL)
        printf("Nepavyko atidaryti failo 'out.txt'\n");
    else {
        fprintf(fp, "%u", fact);
        fclose(fp);
        printf("Faktorialas irasyta i faila 'out.txt'\n");
    }
    printf("Skaiciaus x faktorialas: %u\n", fact);
    return 0;
}
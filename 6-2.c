#include <stdio.h>
#include <ctype.h>

int main(void) {
    printf("Si programa atspausdina realaus skaiciaus, perskaityto is failo ilgi.\n");
    char filename[100] = "in.txt";
    while (1) {
        printf("Issaugokite realu skaiciu faile '%s' ir pasapuskite enter (10 <= skaicius <= 1000, ne daugiau nei 3 skaiciai po kablelio):", filename);
        char c;
        while ((c = getchar()) != '\n')
            if (c == EOF) {
                printf("Pasiekta failo pabaiga. Baigiamas darbas.\n");
                return 1;
            }
        FILE *fp = fopen(filename, "r");
        if (fp == NULL)
            printf("Nepavyko atidaryti failo\n");
        else {
            int finish = 0;
            int whole;
            char fract[4] = "";
            if (fscanf(fp, "%4d", &whole) != 1 || whole < 10 || whole > 1000)
                printf("Nera sveikos dalies, ar virsijami reziai\n");
            else if (fgetc(fp) == ',') {
                if (whole == 1000)
                    printf("Virsijami reziai\n");
                else if (fscanf(fp, "%3[0-9]", fract) != 1)
                    printf("Yra kablelis, bet nera skaiciu\n");
                else
                    finish = 1;
            }
            else
                finish = 1;

            if (finish) {
                int length = 0;
                while (whole) {
                    ++length;
                    whole /= 10;
                }
                int i;
                for (i = 0; fract[i] != '\0'; ++i)
                    ;
                if (i != 0)
                    length += 1 + i;
                printf("Skaiciaus ilgis yra: %d\n", length);
                return 0;
            }
        }

        fclose(fp);

        while(printf("Iveskite failo, is kurio perskaityti skaiciu, varda (ne daugiau nei 99 simboliai): ")) {
            int flag;
            if ((flag = scanf("%9s%c", filename, &c)) != 2 || c != '\n') {
                if (flag == EOF) {
                    printf("Pasiekta failo pabaiga. Baigiamas darbas.\n");
                    return 1;
                }
                printf("Netinkama ivestis\n");
                scanf("%*[^\n]");
            }
            else
                break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int mid(int a, int b, int c) {
    if ((a < b && b < c) || (c < b) && (c < a))
        return b;
    if ((b < a && a < c) || (c < a && a < b))
        return a;
    else
        return c;
}

int main(void) {
    printf("Si programa randa vidurini skaiciu is 3 skaiciu (pagal reiksme) ir uzraso jo reiksme i faila\n");
    int a, b, c;
    while (1) {
        printf("Iveskite tris sveikus skaicius vienoje eiluteje be tarpu atskirtus kabliataskiais: ");
        int flag;
        char ch;
        if ((flag = scanf("%9d;%9d;%9d%c", &a, &b, &c, &ch)) != 4) {
            if (flag == EOF) {
                printf("Pasiekta failo pabaiga. Baigiamas darbas\n");
                return 1;
            }
            else {
                printf("Ivedete neuztektinai skaiciu arba neatskirete juos kabliataskiais\n");
                scanf("%*[^\n]");
            }
        }
        else {
            if (ch != '\n')
                printf("Rasti simboliai po ivedimo\n");
            else
                break;
        }
    }
    printf("Skaiciai nuskaityti sekmingai\n");

    

    char filename[101];
    FILE *fp;
    while (1) {
        printf("Iveskite rezultato failo varda (turi baigtis .txt) ir nevirsyti 100 simboliu): ");
        int flag;
        char ch;
        if ((flag = scanf("%100s%c", filename, &ch)) == EOF) {
            printf("Pasiekta failo pabaiga. Baigiamas darbas\n");
            return 1;
        }
        else {
            char *dot = strchr(filename, '.');
            if (!(dot && strcmp(dot, ".txt") == 0 && *(dot+4) == '\0'))
                printf("Failas nesibaigia .txt\n");
            else if (ch != '\n')
                printf("Rasti simboliai po ivedimo\n");
            else {
                if ((fp = fopen(filename, "w")) != NULL)
                    break;
                else {
                    printf("Nepavyko atidaryti failo\n");
                    return 1;
                }
            }
        }
    }

    fprintf(fp, "%d", mid(a, b, c));
    fclose(fp);
    printf("Programa sekmingai baige darba. Rezultatas issaugotas faile '%s'\n", filename);
    return 0;
}
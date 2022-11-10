#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Si programa patikrina ar ivestas pasto adresas yra teisingas\n");
    char email[1001];
    while (1) {
        printf("Ivesktie pasto adresa (negali virsyti 1000 simbliu): ");
        char ch;
        if (scanf("%1000s%c", email, &ch) != 2 || ch != '\n') {
            printf("Papildomi simboliai po ivesties negalimi\n");
            scanf("%*[^\n]");
        }
        else {
            char *eta = strchr(email, '@');
            if (eta == NULL || eta != strrchr(email, '@')) {
                printf("Nera '@' simbolio ar yra daugiau nei vienas '@' simbolis\n");
                continue;
            }
            char *dot = strchr(eta, '.');
            if (dot == NULL)
                printf("Nera tasko po '@'\n");
            else if (eta - email == 0 || dot - eta == 1 || *(dot + 1) == '\0')
                printf("Neuztenka kitu simboliu\n");
            else {
                printf("Duomenys nuskaityti sekmingai\nDomenas: %s\n", eta + 1);
                FILE *fp = fopen("emails.txt", "a");
                fprintf(fp, "%s\n", email);
                fclose(fp);
                return 0;
            }
        }
    }

    return 0;
}
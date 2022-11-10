#include <stdio.h>

char* convert_to_weekday(int year, int month, int day) {
    int wday = 0;
    /* algorithm from https://www.includehelp.com/c-programs/c-program-print-weekday-of-date.aspx */
    wday = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
               + (365 * (year + 4800 - ((14 - month) / 12)))
               + ((year + 4800 - ((14 - month) / 12)) / 4)
               - ((year + 4800 - ((14 - month) / 12)) / 100)
               + ((year + 4800 - ((14 - month) / 12)) / 400)
               - 32045)
        % 7;

    static char day_str[100] = "\0";

    FILE *fp = fopen("week.txt", "r");
    if (fp == NULL)
        return day_str;
    
    while (wday-- >= 0)
        fscanf(fp, "%99s", day_str);

    fclose(fp);

    return day_str;
}

int main(void) {
    printf("Si programa randa savaites diena, kuri atitinka ivesta data (1800 <= metai <= 2999)\n");
    int year, month, day;
    while (1) {
        printf("Iveskite data formatu YYYY-MM-DD: ");
        char ch;
        if (scanf("%4d-%2d-%2d%c", &year, &month, &day, &ch) != 4 || ch != '\n') {
            printf("Netinkamas formatas\n");
            scanf("%*[^\n]");
        }
        else if (year < 1800 || year > 2999 || month < 1 || month > 12 || day < 1 || day > 31)
            printf("Netinkama data\n");
        else {
            if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
                printf("Pasirinktas menuo neturi tiek dienu\n");
            else if (month == 2 && day > 29)
                printf("Vasaris neturi tiek dienu\n");
            else if (day == 29 && month == 2 && year % 4 != 0)
                printf("Metai nera keliamieji\n");
            else {
                printf("Atitinkama savaites diena - %s\n", convert_to_weekday(year, month, day));
                break;
            }
        }
    }
    return 0;
}
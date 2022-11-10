#include <stdio.h>
#include <math.h>

int main(void) {
    printf("Si programa randa kvadratines lygties ax^2 + bx + c = 0 sprendinius.\n");
    printf("Iveskite lygties koeficentus a, b, c (3 sveikuosius skaicius): ");
    int a, b, c;
    if (scanf("%d%d%d", &a, &b, &c) != 3) {
        printf("Neteisingai ivesti duomenys\n");
        return 1;
    }
    printf("Duomenys nuskaityti sekmingai\n");

    double d = b*b - 4*a*c;
    double x1, x2;

    if (d > 0) {
        x1 = (-b + sqrt(d)) / 2*a;
        x2 = (-b - sqrt(d)) / 2*a;
    }
    else if (d == 0)
        x1 = -b / 2*a;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("0 = 0 (begalybe sprendiniu)\n");
                return 0;
            }
            else 
                d = -1;
        }
        else {
            d = 0;
            x1 = -c / b;
        }
    }

    if (d > 0)
        printf("Yra 2 sprendiniai: x1 = %f, x2 = %f\n", x1, x2);
    else if (d == 0)
        printf("Yra 1 sprendinis: x = %f\n", x1);
    else
        printf("Sprendiniu nera\n");
    return 0;
}
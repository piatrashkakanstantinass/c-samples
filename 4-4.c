#include <stdio.h>

int dbd(int a, int b) {
    if (b == 0)
        return a;
    return dbd(b, a%b);
}

int mbk(int a, int b) {
    return a * b / dbd(a, b);
}

int main(void) {
    printf("Si programa atspausdina 3 skaiciu DBD bei MBK\n");
    printf("Iveskite 3 naturaliuosius skaicius (a, b, c): ");
    int a, b, c;
    if (scanf("%d%d%d", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0) {
        printf("Netinkama ivestis\n");
        return 1;
    }
    printf("Duomenys nuskaityti sekmingai\n");

    printf("DBD(a, b, c) = %d\n", dbd(a, dbd(b, c)));
    printf("MBK(a, b, c) = %d\n", mbk(a, mbk(b, c)));
    return 0;
}
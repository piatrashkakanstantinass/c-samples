#include <stdio.h>

#define CAPACITY 10

void print_arr(int m[], int size, char *s) {
    printf("%s", s);
    for (int i = 0; i < size; ++i)
        printf(" %d", m[i]);
    printf("\n"); 
}

// delete element of index i
void delete(int m[], int *size, int i) {
    for (--*size; i < *size; ++i)
        m[i] = m[i+1];
}

// insert value to index i
void insert(int m[], int *size, int i, int value) {
    for (int j = (*size)++; j > i; --j)
        m[j] = m[j-1];
    m[i] = value;
}

int main(void) {
    printf("Si programa atlieka Radaviciaus nustatytus veiksmus su masyvais\n");

    int size = CAPACITY;
    int m[CAPACITY] = {0}; // a
    int x, y;

    print_arr(m, size, "Masyvas:"); // b

    m[0] = 1, m[3] = 2, m[9] = 3; // c
    delete(m, &size, 2); // d
    insert(m, &size, 6, 4); // e

    print_arr(m, size, "Masyvas po c, d ir e zingsniu:"); // f

    printf("Iveskite tarpu atskirtus 2 sveikus skaicius x ir y, kur x - masyvo indeksas, o y - nauja reiksme: "); // g
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Klaida: netinkama ivestis\n");
        scanf("%*[^\n]");
    }
    else if (x < 0 || x >= size)
        printf("Klaida: masyvo reziu perzengimas\n");
    else
        printf("Duomenys nuskaityti sekmingai\n"), m[x] = y;

    printf("Iveskite sveika skaiciu x (masyvo indeksa): "); // h
    if (scanf("%d", &x) != 1) {
        printf("Klaida: netinkama ivestis\n");
        scanf("%*[^\n]");
    }
    else if (x < 0 || x >= size)
        printf("Klaida: masyvo reziu perzengimas\n");
    else
        printf("Duomenys nuskaityti sekmingai\n"), delete(m, &size, x);
    
    printf("Iveskite tarpu atskirtus 2 sveikus skaicius x ir y, kur x - masyvo indeksas, o y - nauja iterpiama reiksme: "); // i
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Klaida: netinkama ivestis\n");
        scanf("%*[^\n]");
    }
    else if (x < 0 || x > size || size >= CAPACITY)
        printf("Klaida: masyvo reziu perzengimas\n");
    else
        printf("Duomenys nuskaityti sekmingai\n"), insert(m, &size, x, y);

    print_arr(m, size, "Masyvas po visu operaciju: "); // j

    return 0;
}
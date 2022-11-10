#include <stdio.h>
#include <stdlib.h>

long getFileSize(FILE *fp) {
    if (!fp || fseek(fp, 0, SEEK_END) != 0)
        return -1;
    long size = ftell(fp);
    return size;
}

int getValue(FILE *fp, long index) {
    if (index < 0 || index >= getFileSize(fp))
        return -1;
    fseek(fp, index, SEEK_SET);
    return fgetc(fp);
}

int setValue(FILE *fp, long index, int value) {
    if (index < 0 || index >= getFileSize(fp))
        return -1;
    fseek(fp, index, SEEK_SET);
    fputc(value, fp);
    return 0;
}

int addValue(FILE *fp, long index, int value) {
    long size = getFileSize(fp);
    if (index < 0 || index > size)
        return -1;
    char *buff = (char *) malloc(sizeof(char) * (size - index + 1));
    if (!buff)
        return -1;
    fseek(fp, index, SEEK_SET);
    fgets(buff, size - index + 1, fp);
    fseek(fp, index, SEEK_SET);
    fputc(value, fp);
    fputs(buff, fp);
    free(buff);
    return 0;
}

int remValue(FILE *fp, long index) {
    long size = getFileSize(fp);
    if (index < 0 || index >= size)
        return -1;
    char *buff = (char *) malloc(sizeof(char) * size);
    if (!buff)
        return -1;
    fseek(fp, 0, SEEK_SET);
    fgets(buff, index + 1, fp);
    fseek(fp, 1, SEEK_CUR);
    fgets(buff+index, size - index, fp);
    freopen(NULL, "w+b", fp);
    fputs(buff, fp);
    free(buff);
    return 0;
}

int main(void) {
    FILE *fp = fopen("test.txt", "r+b");
    printf("%ld\n", getFileSize(fp));
    printf("%d\n", getValue(fp, 1));
    printf("%d\n", setValue(fp, 1, 50));
    printf("%d\n", addValue(fp, 2, 52));
    printf("%d\n", remValue(fp, 7));
    fclose(fp);
    return 0;
}
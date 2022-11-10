#include <stdio.h>

long getFileSize(char *fileName) {
    FILE *fp;
    if (!(fp = fopen(fileName, "r")))
        return -1;
    if (fseek(fp, 0, SEEK_END) != 0) {
        fclose(fp);
        return -1;
    }
    long size =  ftell(fp);
    fclose(fp);
    return size;
}

int main(void) {
    printf("test.txt - %ld bytes\n", getFileSize("test.txt"));
    return 0;
}
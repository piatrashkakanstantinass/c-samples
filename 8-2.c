#include <stdio.h>

long max(long a, long b) {
    return a > b ? a : b;
}

long get_file_size(FILE *fp) {
    if (!fp || fseek(fp, 0, SEEK_END) != 0)
        return -1;
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return size;
}

long biggest_file(int count, char **filenames) {
    long max_size = -1;
    while (count--) {
        FILE *fp = fopen(*(filenames++), "rb");
        if (fp) {
            max_size = max(max_size, get_file_size(fp));
            fclose(fp);
        }
    }
    return max_size;
}

int main(int argc, char **argv) {

    printf("%ld\n", biggest_file(argc - 1, argv+1));
    return 0;
}
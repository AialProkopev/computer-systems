#include <stdio.h>
#include <math.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (int i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    printf("int bytes in hex = ");
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    printf("float bytes in hex = ");
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    printf("pointer bytes in hex = ");
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_bytes_all_types(int val) {
    int ival = val;
    float fval = (float) val;
    int *pval = &val;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int get_num_from_string(char *str) {
    char *p = str;
    int len = strlen(str);
    int num = 0;
    int i = len - 1;

    while(*p != '\0') {
        num += (*p - '0') * pow(10, i);
        i--;
        p++;
    }

    return num;
}

int is_negative(char first_char) {
    return (first_char == '-');
}

int is_float(char *str) {
    char *p = str;

    while(*p != '\0') {
        if (*p == '.') return 1;
        p++;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("You had to pass one argument\n");
        return 1;
    }
    if (is_negative(argv[argc - 1][0]) || is_float(argv[argc - 1])) {
        printf("You had to enter positive integer\n");
        return 1;
    }
    int num = get_num_from_string(argv[argc - 1]);
    show_bytes_all_types(num);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int readLine(FILE *file, char *buf) {
    int current = 0;
    int result = 0;
    while (buf[current++] != '\n')
        if ((result = fread(buf + current, sizeof(char), 1, file)) != 1)
            break;
    buf[current] = 0;
    return current - 1;
}

int readSpace(FILE *file, char *buf) {
    int current = 0;
    int result = 0;
    while (buf[current++] != '\t')
        if ((result = fread(buf + current, sizeof(char), 1, file)) != 1)
            break;
    buf[current] = 0;
    return current - 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("error\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("error\n");
        return 2;
    }

    char buf[100] = { 0 };
    int result;

    result = readLine(file, buf);
    int m = atoi(buf + 1);
    int n = atoi(buf + 3);

    int *a = malloc(sizeof(int) * m * n);

    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n - 1; j++) {
            readSpace(file, buf);
            a[i * m + j] = atoi(buf + 1);
            for (result = 0; result < 100; result++)
                buf[result] = 0;
        }

        readLine(file, buf);
        a[i * m + n - 1] = atoi(buf + 1);
        for (result = 0; result < 100; result++)
            buf[result] = 0;
    }

    readLine(file, buf); // empty line
    for (result = 0; result < 100; result++)
        buf[result] = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n - 1; j++) {
            readSpace(file, buf);
            printf("%d\t", a[i * m + j] + atoi(buf + 1));
            for (result = 0; result < 100; result++)
                buf[result] = 0;
        }

        readLine(file, buf);
        printf("%d\n", a[i * m + n - 1] + atoi(buf + 1));
        for (result = 0; result < 100; result++)
            buf[result] = 0;
    }

    fclose(file);

    return 0;
}

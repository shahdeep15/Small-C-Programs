#include <stdio.h>
#include <stdlib.h>

#define SIZE 1031 // 1031 is a prime number

int table[SIZE] = { 0 };
// int counter = 0;

void search(int value) {
    int step = 0;
    while (table[(value + step) % SIZE] != 0) {
        if (table[(value + step) % SIZE] == value) {
            printf("present\n");
            return;
        }
        step++;
    }
    printf("absent\n");
    return;
}

void insert(int value) {
    int step = 0;
    while (table[(value + step) % SIZE] != 0) {
        if (table[(value + step) % SIZE] == value) {
            printf("duplicate\n");
            return;
        }
        step++;
    }
    table[(value + step) % SIZE] = value;
    printf("inserted\n");
    return;
}

int readLine(FILE *file, char *buf) {
    int current = 0;
    int result = 0;
    while (buf[current++] != '\n')
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

    char buf[20];
    int result;

    while ((result = readLine(file, buf)) >= 3) {
        int value = atoi(buf + 3);
        if (buf[1] == 'i')
            insert(value);
        else if (buf[1] == 's')
            search(value);
        else
            printf("error\n");

        for (result = 0; result < 20; result++)
            buf[result] = 0;
    }

    fclose(file);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int isPrime(int input) {
    int i, j;
    for (i = 2; i < input; i++)
        for (j = input - 1; j > i; j--)
            if (i * j < input)
                break; // outside the bounds
            else if (i * j == input)
                return 0; // false
    return 1; // true
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("error\n");
        return 0;
    }
    int input = atoi(argv[1]);
    if (input <= 0) {
        printf("error\n");
        return 0;
    }
    if (isPrime(input))
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}

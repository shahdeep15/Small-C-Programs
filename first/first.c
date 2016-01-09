#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("error\n");
        return 0;
    }
    int input = atoi(argv[1]);

    if (input % 2 == 0)
        printf("even\n");
    else
        printf("odd\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// this is a singly linked list
struct linkednode {
    struct linkednode *next;
    int                value;
};

// use stack allocation, and dummy nodes, first and last
struct linkedlist {
    struct linkednode first;
    struct linkednode last;
} list;

void insert(int value) {
    struct linkednode *node = malloc(sizeof(struct linkednode));
    node->value = value;

    struct linkednode *current = &list.first;
    struct linkednode *next = current->next;
    while (next != &list.last) {
        if (value == next->value) { // if it already exists, don't insert
            free(node);
            return;
        }
        if (value < next->value) {
            current->next = node;
            node->next = next;
            return;
        }
        current = next;
        next = current->next;
    }
    current->next = node;
    node->next = &list.last;
}

void delete(int value) {
    struct linkednode *current = &list.first;
    struct linkednode *next = current->next;
    while (next) {
        if (next->value == value) {
            current->next = next->next;
            free(next);
            return;
        }
        current = next;
        next = current->next;
    }
}

void print() {
    struct linkednode *current = list.first.next;
    while (current != &list.last) {
        if (current->next == &list.last)
            printf("%d", current->value);
        else
            printf("%d\t", current->value);
        current = current->next;
    }
    printf("\n");
}

void freex() {
    struct linkednode *current = list.first.next;
    struct linkednode *temp;
    while (current != &list.last) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int readLine(FILE *file, char *buf) {
    int current = 0;
    int result = 0;
    while (buf[current++] != '\n') {
        if ((result = fread(buf + current, sizeof(char), 1, file)) != 1)
            break;
    }
    buf[current] = 0;
    return current - 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("error\n");
        return 0;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("error\n");
        return 2;
    }

    list.first.next = &list.last;

    char buf[20] = { 0 };
    int result;

    while ((result = readLine(file, buf)) >= 3) {
        int value = atoi(buf + 3);
        if (buf[1] == 'i')
            insert(value);
        else if (buf[1] == 'd')
            delete(value);
        else {
            printf("error\n");
            return 0;
        }

        for (result = 0; result < 20; result++)
            buf[result] = 0;
    }

    fclose(file);

    print();
    freex();

    return 0;
}

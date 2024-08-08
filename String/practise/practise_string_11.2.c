#include<stdio.h>
#define INPUT_SIZE 10

void getCharFromStdin2(char *);

void getCharFromStdin2(char *ptr) {
    int i = 0;
    for (i = 0; i < INPUT_SIZE - 1; i++) {
        char p = getchar();
        if (p == '\n' || p == '\t') {
            break;
        }
        *(ptr + i) = p;
    }
    *(ptr + i) = '\0';
}

int main() {
    char *p[INPUT_SIZE] = {};
    getCharFromStdin2(p);
    puts(p);
}

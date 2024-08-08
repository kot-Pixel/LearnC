#include<stdio.h>
#define INPUT_SIZE 10

void getCharFromStdin(char *);

void getCharFromStdin(char *p) {
    for (int i = 0; i < INPUT_SIZE - 1; i++) {
        *(p + i) = getchar();
    }
    *(p + INPUT_SIZE - 1) = '\0';
}

int main() {
    char *p[INPUT_SIZE] = {};
    getCharFromStdin(p);
    puts(p);
}
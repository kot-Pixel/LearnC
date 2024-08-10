#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define INPUT_SIZE 11
#define INPUT_SIZE_2 100
void stringFunction();

int getFirstWoldLength(char *p,int n);

int getFirsetWoldLength(char* p, int n) {
    int result = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (p[i - 1] != ' ' && p[i -1] != '\t' && p[i] != ' ' && p[i] != '\t') {
            result += 1;
        }
    }
    return result;
}

void stringFunction() {
    char some[10][INPUT_SIZE_2] = {};
    char choice[2] = {};
    int value = -1;
    int i;
    for (i = 0; i < 10; ++i) {
        printf("Please input %d string to store to array\n", i + 1);
        if (fgets(some[i], INPUT_SIZE_2, stdin) == NULL) {
            printf("Will exit beacause read eof\n");
            break;
        }
    }
    printf("Exit input source string and exist %d string", i);
    printf("make your choice \n");
    printf("1.打印源字符串列表 2.以ASCII中的顺序打印字符串 3.按长度递增顺序打印字符串 4.按字符串中第1个单词的长度打印字符串 5.退出\n");
    gets(choice);
    value = atoi(choice);
    switch (value) {
    case 1:
        for (int i = 0; i < 10; ++i) {
            fputs(some[i],stdout);
        }
        break;
    case 2:
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                const int iLength = strlen(some[i]);
                const int jLength = strlen(some[j]);
                if (strcmp(some[i], some[j]) < 0) {
                    for (size_t k = 0; k <= iLength; k++)
                    {
                        char p;
                        p = some[i][k];
                        some[i][k] = some[j][k];
                        some[j][k] = p;
                    }
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            fputs(some[i], stdout);
        }
        break;
    case 3:
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                const int iLength = strlen(some[i]);
                const int jLength = strlen(some[j]);
                if (iLength - jLength > 0) {
                    for (size_t k = 0; k <= iLength; k++)
                    {
                        char p;
                        p = some[i][k];
                         some[i][k] = some[j][k];
                         some[j][k] = p;
                    }
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            fputs(some[i], stdout);
        }
        break;
    case 4:
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                const int iLength = strlen(some[i]);
                const int jLength = strlen(some[j]);
                const fist = getFirsetWoldLength(some[i], iLength);
                const second = getFirsetWoldLength(some[j], jLength);
                if (fist - second > 0) {
                    for (size_t k = 0; k <= iLength; k++)
                    {
                        char p;
                        p = some[i][k];
                        some[i][k] = some[j][k];
                        some[j][k] = p;
                    }
                }
            }
        }
        for (int i = 0; i < 10; ++i) {
            fputs(some[i], stdout);
        }
        break;
    default:
        break;
    }
}

int main() {
    stringFunction();
}
#include<stdio.h>
#include<string.h>
#define INPUT_SIZE 11
/*
编写一个函数，把字符串中的内容用其反序字符串代替。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */
void revertString(char *);

void revertString(char *target) {
    const int sourceLength = strlen(target) / 2;
    const int sourceLength2 = strlen(target) - 1;
    for (int i = 0; i < sourceLength; ++i) {
        const char tmp = target[i];
        target[i] = target[sourceLength2 - i];
        target[sourceLength2 - i] = tmp;
    }
}

int main() {
    while(1) {
        char str[INPUT_SIZE] = {};
        char str2[1000] = {};

        printf("Please input source string \n");
        gets(str2);
        if (removeTargetStr("quit", str2) != NULL) {
            break;
        }
        revertString(str2);
        puts(str2);
    }
}

#include<stdio.h>
#include<string.h>
#define INPUT_SIZE 11
/*
编写一个函数接受一个字符串作为参数，并删除字符串中的空格。
在一个程序中测试该函数，使用循环读取输入行，直到用户输入一行空行。
该程序应该应用该函数读取每个输入的字符串，并显示处理后的结果
 */
void removeBlankChar(char *);

void removeBlankChar(char *target) {
    const int charLength = strlen(target);
    int allRepeat = 0;
    for (int i = 0;  i < charLength - allRepeat; i++) {
        int tmp = 0;
        while (target[i + tmp] == ' ' || target[i + tmp] == '\t') {
            tmp += 1;
        }
        if (tmp != 0) {
            for(int j = i + tmp, count = 0; j < charLength - allRepeat; j++, count++) {
                target[i + count] = target[j];
            }
            allRepeat += tmp;
        }
    }
    target[charLength - allRepeat] = '\0';
}

int main() {
    while(1) {
        char str[INPUT_SIZE] = {};
        char str2[1000] = {};
        printf("Please input source string \n");
        gets(str2);
        removeBlankChar(str2);
        if (strlen(str2) == 0) {
            break;
        }
        puts(str2);
    }
}

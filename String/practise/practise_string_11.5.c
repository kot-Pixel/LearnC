#include<stdio.h>
#include<string.h>
#define INPUT_SIZE 11

/*
strncpy(s1, s2, n)函数把s2中的n个字符拷贝至s1中，截断s2，或者有必要的话在末尾添加空字符。如果s2的长度是n或多于n，目标字符串不能以空字符结尾。
该函数返回s1。自己编写一个这样的函数，名为mystrncpy()。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */

char * mystrncpy(char * , const char *, int);

char * mystrncpy(char *target , const char *source, int n) {
    const int sourceLength = strlen(source);
    const int copyLength = sourceLength > n ? n: sourceLength;
    int i;
    for (i = 0; i < copyLength; ++i) {
        target[i] = source[i];
    }
    target[i] = '\0';
    return target;
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
        puts(mystrncpy(str, str2, INPUT_SIZE - 1));
    }
}

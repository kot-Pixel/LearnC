#include<stdio.h>
#include<string.h>
#define INPUT_SIZE 100
/*
设计并测试一个函数，从一行输入中把一个单词读入一个数组中，并丢弃输入行中的其余字符。
该函数应该跳过第1个非空白字符前面的所有空白。将一个单词定义为没有空白、制表符或换行符的字符序列
* */

void removeAllBlank(char **);

void removeAllBlank(char **ptr) {
    printf("before jump %p\n",ptr);
    while(**ptr == ' ' || **ptr == '\t'  || **ptr == '\n') {
        printf("jump to back\n");
        *ptr += 1;
    }
    int count = 0;
    while(*(*ptr + count) != ' ' || *(*ptr + count) == '\t'  || *(*ptr + count) == '\n' ) {
        count++;
    }
    *(*ptr + count) = '\0';
    printf("after jump %p\n",ptr);
}

int main() {
    char buffer[INPUT_SIZE] = {};
    char *pBuffer = buffer;
    //fgets 不会去掉\n
    fgets(buffer,INPUT_SIZE, stdin);
    printf("--------------------\n");
    puts(pBuffer);
    printf("---------buffer  before address %p-----------\n", pBuffer);
    removeAllBlank(&pBuffer);
    printf("---------buffer  after address %p-----------\n", pBuffer);
    puts(pBuffer);
    printf("---------");
}
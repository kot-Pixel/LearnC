#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define INPUT_SIZE 11
#define INPUT_SIZE_2 100
/*
12．编写一个程序，读取输入，直至读到EOF，报告读入的单词数、大写字母数、小写字母数、标点符号数和数字字符数。使用ctype.h头文件中的函数。
*/

int readFile();

int readFile() {
    int digitCount = 0;
    int punctCount = 0;
    int slowCount = 0;
    int upperCount = 0;
    int notGraphCount = 0;
    char lastReadChar = ' ';
    while (1) {
        char readChar = getchar();
        //Window上EOF表示ctrl + z然后回车Enter。
        if (readChar != EOF) {

            //判断是否是数字。
            if (isdigit(readChar)) {
                digitCount += 1;
            }

            //判断是否是符号。
            if (ispunct(readChar)) {
                punctCount += 1;
            }

            //判断是否是小写
            if (islower(readChar)) {
                slowCount += 1;
            }

            //判断是否是大写
            if (isupper(readChar)) {
                upperCount += 1;
            }

            //isspace()判断是否是空格。
            //isalpha()判断是字符。

            if (isspace(readChar) && isalpha(lastReadChar)) {
                notGraphCount += 1;
            }
            lastReadChar = readChar;
        }
        else {
            break;
        }
    }
    printf("notGraphCount : %d\n", notGraphCount);
    printf("upperCount : %d\n", upperCount);
    printf("slowCount : %d\n", slowCount);
    printf("digitCount : %d\n", digitCount);
    printf("blankGraphCount : %d\n", punctCount);
}



int main() {
    readFile();
}

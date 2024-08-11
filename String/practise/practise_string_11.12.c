#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
/*
    使用字符分类函数实现atoi()函数。如果输入的字符串不是纯数字，该函数返回0
*/
int readAtoi(char *);

int readAtoi(char *p) {    
    int charLength = strlen(p);

    int dis = 0;
    for (size_t i = 0; i < charLength; i++)
    {
        if (isdigit(p[i])) {
            dis += 1;
        }
    }

    if (dis == charLength) {
        return atoi(p);
    }
    else {
        return 0;
    }
}
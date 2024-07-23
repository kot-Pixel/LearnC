#include <stdio.h>

int main()
{
    char *p = "123456";
    char arr[] = "ertyuiop";
    printf("str printf is %s\n", p);
    printf("str printf is %p\n", p);
    printf("arr printf is %s\n", arr);
    return 0;
}

// %s 会输入一个指针变量对应地址开始然后一直输出之道遇上了\0为止停下。 %s 输出格式的时候不需要进行解引用，直接使用指针变量即可。这个过程和
//输出字符串arr的直接使用数组名即可。

//其他的方式是 %d / 或者%c 都是输出一个具体的value而非一个指针。
#include <stdio.h>

int main()
{
    int* p = NULL;
    int *p2 = NULL;
    int * p3 = NULL;

    //上述声明了三个指针变量。

    int var = 13;

    p = &var;
    p2 = p + 1;
    p3 = p + 2;

    // *p = 12;

    //下面这些和上面表达的含义是不一样的，下面的*表示解引用符号，主要是读取指针变量中对应地址的值。
    printf("pointer * address value is : %d\n", (*p));
    printf("pointer2 * address value is : %d\n", (*p2));
    printf("pointer3 * address value is : %d\n", (*p3));
    printf("pointer address value is : %p\n", p);
    printf("pointer2 address value is : %p\n", p2);
    printf("var address value is : %p\n", &var);

    //指针变量的运算.指针变量之间只可以做减法运算不能最加法运算。
    printf("pointer val : %lld", (p2 - p));

    return 0;
}
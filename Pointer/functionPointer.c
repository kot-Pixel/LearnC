#include <stdio.h>
#include <stdlib.h>

//定义一个functionWrap
typedef int (*functionWrap)(int, int);

int add(int, int);

int add(int a, int b)
{
    printf("function add invoke and param is %d and %d \n", a, b);
    return a + b;
}

int minus(int a, int b)
{
    printf("function add invoke and param is %d and %d \n", a, b);
    return a - b;
}

int (*ptr)(int, int);

void ffunctin(int (*ptr)(int, int), int a, int b);

void ffunctin(int (*ptr)(int a, int b), int a, int b)
{
    int funrt = ptr(a, b);
    printf("ffunctin invoke and: %d\n", funrt);
}

int comple(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int (*ptr)(int, int), (*o)(int, int);
    int result = add(1, 2);
    ptr = add;
    o = &add;
    printf("add function result is: %d\n", result);
    printf("function pointer is %p\n", ptr);
    printf("function pointer is %p\n", *ptr);
    int result2 = (*ptr)(2, 3);
    int result3 = (*o)(2, 3);
    printf("add function result2 is: %d\n", result2);
    printf("add function result3 is: %d\n", result3);

    printf("------------------\n");

    ffunctin(ptr, 1, 2);
    ffunctin(minus, 1, 2);

    printf("-----------------------------\n");

    int (*ppp[2])(int, int) = {add, minus};

    printf("function pointer array result is : %d\n", ppp[0](1, 2));
    printf("function pointer array result2 is : %d\n",(*(ppp + 1))(1, 2));

    int arr[] = {1, 5, 23, 5, 6, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]), i;
    qsort(arr, n, sizeof(int), comple);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return -1;
}

//int (*pointer_name)(param args)来定义一个函数指针。
//上述main函数中定义了两个函数指针以及一个函数指针常量，类型为int (*) (int, int)名称为的ptr的指针， int (*) (int)名称为 o的指针以及
//int (*) (int, int)类型名称为add的函数指针常量。本质上函数是代表着一段逻辑/功能，但是在C语言中， add作为函数名，它本质上一个函数指针的常量。
//ptr和o函数指针的变量。

//可以看到函数指针的的赋值：ptr = add;和o = &add;都是函数指针的变量赋值方式。直接将函数指针常量赋值给变量或者可以使用引用符号来赋值。
//函数指针指向函数之后，(*ptr)(1,2)可以通过解引用的方式去调用函数。或者直接使用函数指针变量去调用函数o(2,3).函数指针可以直接使用*o或者指针名
//来直接分配。

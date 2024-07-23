#include<stdio.h>

int swap(int a, int b)
{
    int tmp = b;
    b = a;
    a = tmp;
    return 9;
}

int swapPointer(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
    return 9;
}

int main()
{
    int a =0 ,b =9;

    printf("before function invoke is %d and %d \n", a , b);

    swapPointer(&a, &b);

    printf("after function invoke is %d and %d \n", a , b);

    //invoke swap result is 

    //before function invoke is 0 and 9
    //after function invoke is 0 and 9

    //invoke swapPointer result is 

    //before function invoke is 0 and 9
    //after function invoke is 9 and 0
}

//上面表示函数参数传递的方式存在两种，值传递和引用传递。上面的code就可以看到两个明显的区别。


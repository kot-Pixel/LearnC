#include <stdio.h>

int main()
{
    int var0 = 0;
    int *p = var0;
    int varA = 1;
    int* ptrA = &varA;
    int varB = 2;
    int* ptrB = &varB;

    int varC = 3;
    int* ptrC = &varC;

    int varD = 4;
    int* ptrD = &varD;
    int* pointerArray[5] = {ptrA, ptrB, ptrC, ptrD};

    printf("pointer array size is %lu \n", sizeof(pointerArray));
    printf("pointer size is %lu \n", sizeof(p));

    printf("pointer1 address is %p \n", pointerArray[0]);
    printf("pointer1 value is %d \n", *pointerArray[0]);

    printf("pointer2 address is %p \n", pointerArray[1]);
    printf("pointer2 value is %d \n", *pointerArray[1]);

    printf("pointer3 address is %p \n", pointerArray[2]);
    printf("pointer3 value is %d \n", *pointerArray[2]);

    printf("pointer4 address is %p \n", pointerArray[3]);
    printf("pointer4 value is %d \n", *pointerArray[3]);

    //尚未初始化的pointer指针的地址为NULL的。
    if (pointerArray[4] == NULL)
    {
        printf("current pointer is NULL pointer\n");
    } else
    {
        printf("pointer4 address is %p \n", pointerArray[4]);
        printf("pointer4 value is %d \n", *pointerArray[4]);
    }

    /**
    *pointer array size is 40
    pointer array size is 8
    pointer1 address is 000000af5d3ffb9c
    pointer1 value is 1
    pointer2 address is 000000af5d3ffb98
    pointer2 value is 2
    pointer3 address is 000000af5d3ffb94
    pointer3 value is 3
    pointer4 address is 000000af5d3ffb90
    pointer4 value is 4
    current pointer is NULL pointer
    */

    //类似 *pointer_name[] / * pointer_name[]等等都是定义为指针数组。可以理解为指针的数组，其中数组中每一个元素都是一个指针。上面的例子中
    // pointer[0] / pointer[1] / pointer[2] 。。。。。等都是的指针。可以看到指针变量的长度打印为8位也就是一个字节。
    //由于数组下标运算符的优先级是高于 * (解引用)运算符的。所有优先是一个数组，数组存储都是指针变量。

    printf("---------------------------------\n");


    int (*arrPointer2)[4];

    int arr[] = {1,2,3,4};

    arrPointer2 = arr;

    printf("arr pointer is %d \n", (*arrPointer2)[0]);

    int *o = 1;

    //上面的arrPoninter2即为一个数组指针，可以看到使用&arr
    return 0;
}





#include<stdio.h>
#define CLOS 4

int sumAllElem(int (*)[CLOS], int);
//指针数组和二维数组的方式都可以修改成可变数组的方式。
int sumAllElemVla(int, int, int (*)[*]);
int sumAllElem2(int [][CLOS], int);

int sumAllElem(int (*arr)[CLOS], int ros)
{
    int i,j;
    int sum = 0;
    for (i = 0; i< ros; i++)
    {
        for (j = 0; j < CLOS; j++)
        {
            sum += *(*(arr + i) + j);
        }
    }

    return sum;
}

int sumAllElemVla(int ros,int m,int (*arr)[m])
{
    int i,j;
    int sum = 0;
    for (i = 0; i< ros; i++)
    {
        for (j = 0; j < m; j++)
        {
            sum += *(*(arr + i) + j);
        }
    }

    return sum;
}

int sumAllElem2(int arr[][CLOS], int ros)
{
    int i,j;
    int sum = 0;
    for (i = 0; i< ros; i++)
    {
        for (j = 0; j < CLOS; j++)
        {
            sum += *(*(arr + i) + j);
        }
    }

    return sum;
}

//请注意， ros和m的顺序必须是在数组形参之前的，否则不能确定数组的长度。
//int sumAllVlaArray(int[ros][m], int ros, int m); 这样的写法是不正确的，
int sumAllVlaArray(int ros, int m, int[ros][m]);

//还可以这样去定义。使用 *来代替前面的两个形参。
//int sumAllVlaArray(int, int, int[*][*]);

int sumAllVlaArray(int ros, int m, int arr[ros][m])
{
    int i,j;
    int sum = 0;
    for (i = 0; i< ros; i++)
    {
        for (j = 0; j < m; j++)
        {
            sum += *(*(arr + i) + j);
        }
    }

    return sum;
}
int main()
{
    printf("vla \n");
    int arr[1][4] = {{1, 2, 3, 4}};
    int arr2[2][4] = {{1, 2, 3, 4},{54,4,56,24}};
    printf("result is %d \n", sumAllElemVla(2,4, arr2));
    printf("result2 is %d \n", sumAllElem(arr, 1));

    /*
     * 之前了解将数组作为参数传递的时候，需要确定一列是有几个元素的。否则无法处理数组的正确指向导致出现问题。但是存在一些情况下，需要针对不同长度
     * 的数组使用相同的函数来，这个使用不同行个数元素值的函数是代码复用性太低了。
     *
     * C99标准中提出了可变长度的数组。但是需要注意一些事情：
     * 可变的变不是指可以修改已创建数组的大小。一旦创建了变长数组，它的大小则保持不变。这里的变指的是：在创建数组时，可以使用变量指定数组的维度。
     *
     * 数组大小不会产生变化，可以变化的是数组维度。
     */
    printf("result2 is %d \n", sumAllVlaArray(2,4,arr2));

    /**
     * 函数形参中传入数组的时候并不会产生值的拷贝，形式参数本质上是一个指针，所以形式参数在修改参数的时候也可以修改实际参数。
     * 并且普通的数组内存大小都是静态的编译出来的。
     */
    return 0;
}

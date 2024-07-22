#include<stdio.h>

void printMultiArray(int arr[][4], int n, int m);
//void printMultiArray(int **arr, int n, int m);
//不能使用多维指针。

/**
* 多维数组传递的时候，必须要写明除了最左面其他维度的长度。数组是存储方式是顺序存储的方式，如果的不存在后续维度长度的话，那么不能确定
* 后续维度参数的内存地址的
    arr[0][0], arr[0][1], arr[0][2], arr[0][3], arr[1][0], arr[1][1], arr[1][2], arr[1][3]
    二数组数组：
    a[i][j]的地址 = 基地址 + (i * m + j) * sizeof(int)
    如果不指定第二维度的长度的话，这个时候就会产生找不到地址的问题。
*/
void printMultiArray(int arr[][4], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
//不能使用多维指针来完全数组在函数调用时的传参。

/**
void printMultiArray(int** arr, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
*/

int main() {
    int multiArray[2][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    printf("printMultiArray\n");
    printMultiArray(multiArray, 2, 4);
    printf("name of array present of address is %p \n", multiArray);
    /*
    * 在单维度数组中，类似arr_name[index]肯定是表示值，但是类似在多维数组中，arr_name[index]表示不是一个值而是一个地址。
    * 他表示arr[index][0]的地址。所以 multiArrayName == multiArrayName[0] == &multiArrayName[0][0]
    * 这三者的地址都是相同的
    * */
    printf("the first member of address is %p \n", multiArray[0]);
    printf("the first member of address is %p \n", &multiArray[0][0]);

    /*
    * 对数组名称进行解引用，应该是打印出arr_name[0]中所存储的值的。确实是存储着第一个元素的值，只是在多维度数组中arr_name[0]存储着就是
    * 下一维度的地址， 即 &arr_name[0][0]. 这四个值都是 *arr_name == arr_name == arr_name[0] == &arr_name[0][0]
    * */
    printf("address is %p \n", *multiArray);

    /*
    * 上述中判断多维数组下arr_name[0]是一个地址，那对其解引用可以得到存储的值, 从之前的单维度数组来看的话。使用 *或者[]都以可以解引用。
    * 这里就可以打印出多维度数组的第一个值。
    * */
    printf("first member of address is %d \n", *multiArray[0]);
    printf("first member of address is %d \n", multiArray[0][0]);

    /*
    *  请注意，进行指针运算过程中，arr_name + 1 之后得出的地址和 arr_name[0] + 1是不相同的。arr_name + 1的地址是 arr_name[1]是相等。
    * arr_name[0] + 1和 &arr[0][1]的地址是相同的。arr_name + 1 可以理解成对 行个数 * int所占字节数量。arr_name[0] + 1 可以理解成
    * int的字节数。
    *
    * 而且在单维数组的时候，两个指针变量可以做减法，但是需要保证指针变量进行减法运算的时候是相同的类型。
    * */
    printf("sencond member of address is %p \n",(multiArray + 1));
    printf("sencond member of address is %p \n",(multiArray[1]));
    printf("sencond member of address is %p \n",(multiArray[0] + 1));
    printf("sencond member of address is %p \n",&(multiArray[0][1]));

    //printf("sencond member of address is %d \n",((multiArray + 1) - (multiArray[0])));

    printf("sencond member of address is %p \n",&(multiArray[1]));
    printf("sencond member of address is %p \n",(multiArray + 1));

    /*
    * 访问数组的元素，如果使用方括号去访问的话需要使用两个方括号。使用指针变量来访问的话，也是需要解引用两次。
    * 使用指针变量来进行访问的时候相对[][]比较麻烦些，因为涉及到运算。多层次的话内部指针表达行，外部的指针代表着列。
    * */
    printf("array item access %d\n", multiArray[0][0]);
    printf("array item access %d\n", **multiArray);
    //这里访问的是 multiArray[1][0]
    printf("array item access %d\n", **(multiArray + 1));
    //这里访问的是 multiArray[1][1]
    printf("array item access %d\n", *(*(multiArray + 1) + 1));
    //这里访问的是 multiArray[1][3]
    printf("array item access %d\n", *(*(multiArray + 1) + 3));
    //这里访问的是 multiArray[0][3]
    printf("array item access %d\n", *(*multiArray + 3));

    /*
    *  当然 [] 和 * 也是可以混合在一起进行运算的。由于他的优先级来说[]的优先级是高于 * 运算符的。所以
    * 表示[1][0]位置的数。
    * */
    printf("array item access %d\n", *multiArray[1]);

    return 0;
}

#include<stdio.h>

/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

int* plusOne(int* digits, int digitsSize, int* returnSize);

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* add = (int*)malloc((digitsSize + 1) * sizeof(int));
    int insertflag = 0;
    int index = -1;
    for (index = digitsSize - 1; index >= 0; index--) {
        if (digits[index] != 9) {
            break;
        }
    }
    if (index == -1) {
        *returnSize = digitsSize + 1;
        add[0] = 1;
        for (size_t in = 1; in <= digitsSize; in++) {
            add[in] = 0;
        }
    }
    else {
        for (size_t in = 0; in < digitsSize; in++) {
            if (in == index) {
                add[in] = digits[in] + 1;
            }
            else {
                if (in > index) {
                    add[in] = 0;
                }
                else {
                    add[in] = digits[in];
                }
            }
        }
        *returnSize = digitsSize;
    }
    return add;
}
/*
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/
#include<stdio.h>
int* getRow(int rowIndex, int* returnSize);
int* getRow(int rowIndex, int* returnSize) {
    int count = ((rowIndex + 2) * (rowIndex + 1) / 2);
    int* result = (int*)malloc(count * sizeof(int));
    *returnSize = rowIndex + 1;
    int index = 0;
    for (int i = 0; i < rowIndex + 1; i++) {
        for (int j = 1; j <= i + 1; j++) {
            if (j == 1 || j == (i + 1)) {
                result[index] = 1;
                index++;
            }
            else {
                result[index] = result[index - i - 1] + result[index - i];
                index++;
            }
        }
    }
    return result + index - (*returnSize);
}
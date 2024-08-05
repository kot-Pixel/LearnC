/*
����һ���Ǹ����� rowIndex�����ء�������ǡ��ĵ� rowIndex �С�

�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�
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
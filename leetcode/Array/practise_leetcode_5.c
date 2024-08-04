
#include<stdio.h>

/*
����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��
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
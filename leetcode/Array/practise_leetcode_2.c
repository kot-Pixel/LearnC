#include<stdio.h>
/*
����һ�� ���ϸ�������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����

���� nums ��ΨһԪ�ص�����Ϊ k ������Ҫ����������ȷ����������Ա�ͨ����

�������� nums ��ʹ nums ��ǰ k ��Ԫ�ذ���ΨһԪ�أ���������������� nums �г��ֵ�˳�����С�nums ������Ԫ���� nums �Ĵ�С����Ҫ��
���� k ��
*/

int removeDuplicates(int* nums, int numsSize);

// 1 2 3 4 4  4 5
int removeDuplicates(int* nums, int numsSize) {

    int p;
    int count = 0;
    for (size_t i = 0; i < numsSize - 1 - count; i++)
    {
        p = 0;
        while (nums[i] == nums[i + p + 1] & i + p + 1 <= numsSize - 1 - count) {
            p += 1;
        }
        for (size_t j = i + p; j < numsSize - count; j++) {
            nums[j - p] = nums[j];
        }
        count += p;
    }
    printf("wwwwwwwwwwww %d\n" ,count);
    printf("wwwwwwwwwwww %d\n" , count);
    printf("wwwwwwwwwwww %d" , (numsSize - count));
    return (numsSize - count);
}
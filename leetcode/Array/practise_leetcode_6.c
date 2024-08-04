#include<stdio.h>

/*
���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��

���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�

ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int tmp = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (nums1[i] <= nums2[j]) {
                continue;
            }
            else {
                tmp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = tmp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        nums1[m + i] = nums2[i];
    }
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define INPUT_SIZE 11
#define INPUT_SIZE_2 100

/*
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 
*/
bool containsDuplicate(int* nums, int numsSize);

int cmpfunc(const void *a,const void *b) {
    return *(int *)(a) - *(int *)(b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < numsSize - 1; i++) {
        if(nums[i] == nums[i + 1]) return 1;
    }
    return 0;
}

void quickSort(int array[], const int start, const int end) {
    const int mid = array[start];
    int left = start;
    int right = end;
    if (start >= end) return;
    while(left != right) {
        while (array[right] >= mid && left < right) {
            right -= 1;
        }
        while (array[left] <= mid && right > left) {
            left += 1;
        }
        if(left < right) {
            const int tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;
        }
    }
    array[start] = array[left];
    array[left] = mid;
    quickSort(array, start, left - 1);
    quickSort(array, left + 1, end);
}

/**
 * 这里主要先使用C库函数排序对数组进行排序，当然这个排序是使用快速排序。
 * 
 * 快速排序的思想是分治的思想，先选择的一个数组的基点。一次循环中会交换基点两端的数字。等到循环完成之后的，基点之后数字肯定是比基点要大，基点之前的数字肯定比基点要小。
 * 之后递归调用将的0 - 基点作为新的参数排序。 基点 - end作为新的参数排序。
 * 这样就完成快速排序。
 */
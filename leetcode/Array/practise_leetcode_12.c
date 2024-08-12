#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stdbool.h>

int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int result = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (result == nums[i]) {
            count += 1;
        } else {
            count -= 1;
        }
        if (count == 0) {
            result = nums[i];
            count += 1;
        }
    }

    return result;
}

/*
博耶-摩尔多数投票算法.
 */
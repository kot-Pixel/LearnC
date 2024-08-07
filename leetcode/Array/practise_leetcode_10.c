/*
给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
 */
int singleNumber(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    int x  = 0;
    for (int i = 0;i < numsSize; i++) {
        x ^= nums[i];
    }
    return x;
}

/*
    上述是正确的算法， 下面是错误算法。包含想法过程:
    想法是：判断数组的综合是否是奇数偶数来判断， 但是这是不正确的，因为无法确定多余的数的奇偶性，从而无法确定是否是多余出来的数字。
 */

int singleNumber(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    int midIndex = numsSize / 2;
    int prSum = 0;
    int prFlag = 0;
    int pr2Sum = 0;
    for (int i = 0;i < midIndex; i++) {
        prSum += nums[i];
        if (nums[i] == nums[midIndex]) {
            prFlag = 1;
        }
    }

    for (int i = midIndex + 1;i < numsSize; i++) {
        pr2Sum += nums[i];
    }

    if (prSum == pr2Sum) return nums[midIndex];

    if (prFlag) {
        return pr2Sum - (prSum - nums[midIndex]);
    } else {
        return prSum - (pr2Sum - nums[midIndex]);
    }
}

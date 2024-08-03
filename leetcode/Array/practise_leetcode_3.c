/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/
int searchInsert(int* nums, int numsSize, int target) {
    if (numsSize == 0) {
        return nums[0] >= target ? 0 : 1;
    }
    else {
        int start = 0, end = numsSize - 1;
        int mid = (start + end) / 2;
        while (start < mid) {
            if (nums[mid] == target) {
                return mid;
            }
            else {
                if (nums[mid] > target) {
                    end = mid;
                }
                else {
                    start = mid;
                }
            }
            mid = (start + end) / 2;
        }

        if (nums[end] < target) {
            return end + 1;
        }
        else if (nums[start] >= target) {
            return start;
        }
        else {
            return end;
        }
    }
}
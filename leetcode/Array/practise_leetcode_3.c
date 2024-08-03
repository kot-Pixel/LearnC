/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
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
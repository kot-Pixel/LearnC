/*
����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�ء�Ԫ�ص�˳����ܷ����ı䡣Ȼ�󷵻� nums ���� val ��ͬ��Ԫ�ص�������

���� nums �в����� val ��Ԫ������Ϊ k��Ҫͨ�����⣬����Ҫִ�����²�����

���� nums ���飬ʹ nums ��ǰ k ��Ԫ�ذ��������� val ��Ԫ�ء�nums ������Ԫ�غ� nums �Ĵ�С������Ҫ��
���� k��
*/

int removeElement(int* nums, int numsSize, int val) {
    int i, k = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i];
        }
    }
    return k;
}
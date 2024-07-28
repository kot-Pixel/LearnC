/*
编写一个函数，返回存储在double类型数组中最大值的下标，并在一个简单的程序中测试该函数。
*/

#include<stdio.h>
size_t getMaxFormArrayIndex(int[], int size);

size_t getMaxFormArrayIndex(int arr[], int size)
{
	if (size == 0) return -1;
	if (size == 1) {
		return 0;
	}
	size_t index = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > arr[index]) {
			index = i;
		}
	}
	return index;
}
/*
int main() {
	printf("pointer practise\n");

	int arr[10] = {
		8541,44741,715851,1454,1554,1795699,185541,4444714,4412621,1441
	};

	size_t t = getMaxFormArrayIndex(arr, 10);
	printf("result is %llu\n", t);
	return 0;
}
运行结果：
result is 7
*/
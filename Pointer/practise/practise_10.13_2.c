/*
编写一个函数，返回存储在int类型数组中的最大值，并在一个简单的程序中测试该函数。
*/

#include<stdio.h>
int getMaxFormArray(int[], int size);

int getMaxFormArray(int arr[], int size)
{
	if (size == 0) return 0;
	if (size == 1) {
		return arr[0];
	}
	int result = arr[0];
	
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > result) {
			result = arr[i];
		}
	}
	return result;
}

/*
int main() {
	printf("pointer practise\n");

	int arr[10] = {
		8541,44741,715851,1454,1554,1795699,185541,4444714,4412621,1441
	};

	int t = getMaxFormArray(arr, 10);
	printf("result is %d\n", t);
	return 0;
}

result is 4444714
*/
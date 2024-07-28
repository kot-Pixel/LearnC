/*
编写一个函数，返回存储在double类型数组中最大值和最小值的差值，并在一个简单的程序中测试该函数
*/

#include<stdio.h>
double getInterpolationFormArrayIndex(double[], int size);

double getInterpolationFormArrayIndex(double arr[], int size)
{
	if (size == 0 || size == 1) return 0.0L;

	int minIndex = 0 , maxIndex = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > arr[maxIndex]) {
			maxIndex = i;
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < arr[minIndex]) {
			minIndex = i;
		}
	}

	if (maxIndex == minIndex) return 0.0L;

	double result = (arr[maxIndex] - arr[minIndex]);
	printf("%f\n", result);
	return result;
}
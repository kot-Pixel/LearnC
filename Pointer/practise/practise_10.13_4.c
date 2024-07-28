/*
��дһ�����������ش洢��double�������������ֵ����Сֵ�Ĳ�ֵ������һ���򵥵ĳ����в��Ըú���
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
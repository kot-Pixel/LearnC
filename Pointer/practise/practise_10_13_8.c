/*
��дһ�����������������������Ӧ��Ԫ����ӣ�Ȼ��ѽ���洢����3��������
Ҳ����˵���������1�а�����ֵ��2��4��5��8������2�а�����ֵ��1��0��4��6��
��ô�ú�����3��4��9��14������3�����顣��������3����������һ�������С����һ���򵥵ĳ����в��Ըú�����
*/
#include<stdio.h>

void addArray(int[], int[], int[], int size);

void addArray(int arr1[], int arr2[], int arr3[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
	}
}

/*
int main() {
	int arr[4] = { 1,1,1,1 };
	int arr2[4] = { 2,3,4,5 };
	int arr3[4];

	printfArrayInt(arr, 4);
	printfArrayInt(arr2, 4);

	addArray(arr, arr2, arr3, 4);

	printfArrayInt(arr3, 4);
}

1 1 1 1
2 3 4 5
3 4 5 6
*/
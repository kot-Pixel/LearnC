/*
编写一个函数，把两个数组中相对应的元素相加，然后把结果存储到第3个数组中
也就是说，如果数组1中包含的值是2、4、5、8，数组2中包含的值是1、0、4、6，
那么该函数把3、4、9、14赋给第3个数组。函数接受3个数组名和一个数组大小。在一个简单的程序中测试该函数。
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
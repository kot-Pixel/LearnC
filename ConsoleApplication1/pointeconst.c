#include<stdio.h>

void printArray(const int* p, int size_t);
void printArray2(int* p, int size_t);

void printArray(const int* p, int size_t) {

	int i;
	for (i = 0; i < size_t; i++)
	{
		printf("%d ", *(p + i));
	}

	printf("\n");
}

void printArray2(int* p, int size_t) {

	int i;
	for (i = 0; i < size_t; i++)
	{
		printf("%d ", *(p + i));
		*(p + i) = i;
	}
	printf("\n");
	for (i = 0; i < size_t; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
}



int pointConst() {

	const int arr[10] = { 1466,121,454,4547,198,557,255,754,733,11 };
	int arr2[10] = { 1466,121,454,4547,198,557,255,754,733,11 };

	//编译失败的，arr数组使用const进行修饰了，表示此数组不能够进行赋值。

	//arr[0] = 1;

	const int* p = arr;
	 int const * p = arr;

	//*p = 0;赋值失败, const int 表示不能进行赋值的。但是可以是修改地址的。

	//arr2[0] = 2;//可以赋值 arr2可以修改。

	p = arr + 3;//这个是合法的，const int 表示不能赋值但是可以重新给地址。

	//const / 非const 修饰的数组都是传参给const数组的。
	//printArray(arr2, 10);
	//printArray(arr, 10);

	/*
	1466 121 454 4547 198 557 255 754 733 11
	0 1 2 3 4 5 6 7 8 9
	*/
	//虽然将const数组赋值传递参数给非const数组的话，编译器上不会报错。但是结果是未定义的。
	printArray2(arr, 10);
	//printArray2(arr2, 10);

	

	return 0;
}
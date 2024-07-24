#include<stdio.h>

int compandArrayValue(void);

void printArrayCompond(int *, int);
void printArrayCompond2(int (*)[3], int);

void printArrayCompond(int *p, int z)
{
	for (size_t i = 0; i < z; i++)
	{
		printf("%d ", *(p + i));
	}

	printf("\n");
}

void printArrayCompond2(int (*p)[7], int z)
{
	for (size_t i = 0; i < z; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}


int compandArrayValue() {

	//复合字面量就是相对于 'c'/1/0.2f/类似的字面量，它代表着数组的常数字字面量。

	int arr[3] = { 1,2,3 };

	//不能直接将复合数组字面量直接赋值给数组变量。下面这个代码是错误的。
	//int add[3] = (int []){ 12,12,3 };
	(int[]) {
		12, 12, 3
	}; // 一维数组的复合字面量。

	(int[][7]) {
		{ 1, 2, 3, 4 },
		{ 2,6,8,4 }
	}; //二维数组的复合字面量。
	int* p = NULL;

	p = &(int[]){ 1,2,3 };

	int (*pointer)[7] = (int[][7]){
		{ 1, 2, 3, 4 },
		{ 2,6,8,4 }
	};

	printArrayCompond(p,3);

	printf("- - - - - - - - - - - -\n");

	printArrayCompond((int[]) { 1, 2, 3 },3);

	printf("- - - - - - - - - - - -\n");
	printArrayCompond2(pointer, 2);

	return 0;
}
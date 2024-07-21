#include <stdio.h>
#define ARR_INDEX 10

void arrayTest(void);

void arrayTest() {
	printf("invoke array Test\n");

	/*
		如果出现index的个数大于数组初始化的时候 {} 给定的数量的时候，那么这个时候其他index就会赋值为0.
		arr现在是可以赋值的，假设如果使用 const 来修饰数组的时候，说明此数组是不可以更改的，这个时候arr[0] = 1;类似的赋值方式就是不合理了。
	*/
	int arr[ARR_INDEX] = { 1,2,3,4,5,6,7 };

	int i,j;

	for (i = 0; i < ARR_INDEX; i++)
	{
		printf("%d - - - - - index: %d \n", arr[i], i);

		arr[i] = i;
	}
	printf("array printf agine \n");

	for (i = 0; i < ARR_INDEX; i++)
	{
		printf("%d - - - - - index: %d \n", arr[i], i);
	}
	
	printf("---------------------\n");

	/*
		这里也可以使用此 [index]来指定index下标特定的值。
	*/
	int arr2[] = {1,2,3,[2] = 4 };

	for (i = 0; i < ARR_INDEX; i++)
	{
		printf("%d - - - - - index: %d \n", arr2[i], i);
	}

	printf("---------------------\n");

	//int arr3[ARR_INDEX];

	//arr3 = arr2;

	//不允许如此赋值，将一个数组赋值给另外的一个数组名称上。后面可以知道arr3函数名称本质上不是变量，是一个右值而不是左值。直接去赋值是不正确的。

	//for (i = 0; i < ARR_INDEX; i++)
	//{
	//	printf("%d - - - - - index: %d \n", arr3[i], i);
	//}

	int x = 3, o = 10;
	int rainArray[3][10] = {
		{1,2,3,4,5,6,7,8,9,10},
		{1,2,3,4,5,6,7,8,9,10},
		{1,2,3,4,5,6,7,8,9,10},
	};

	int rainArray2[3][10] = {
		{1,2}, {1, [4] = 5}
	};

	//上述是初始化二维数组的方式。

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < o; j++)
		{
			printf("%d ", rainArray2[i][j]);
		}

		printf("\n");
	}
	
	return 0;


}
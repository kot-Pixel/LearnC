/*
	了解指针的兼容性。
*/
#include <stdio.h>

void printArray(int(*p)[3], int);

void compatibilityOfPointer(void);


void printArray(int(*p)[3], int z)
{
	for (size_t i = 0; i < z; i++)
	{
		for (size_t j = 0;  j < 3;  j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}

void compatibilityOfPointer()
{
	int varInt = 1;
	double dbVar = 0.5F;

	//dbVar = varInt;

	//编译和运行的时候，这个赋值都是正确的，但是指针相对于普通的变量，其对于指针类型的兼容性相对比较严格。
	//printf("%f", dbVar);

	//类型是int *
	int* pointer = &varInt;
	double* dbPointer = &dbVar;
	//这里编译不会报错了，将 int *的指针赋值给double *也不会报错, 编译器会报报警
	dbPointer = pointer;

	printf("%d\n", *dbPointer);
	printf("----------------------------------\n");

	int arr[3][3] = {
		{ [1] = 2, [0] = 5},{[2] = 4}, {1,2,3}
	};

	int(*arrPointer)[3] = arr; //指针的数组指向一个二维度数组，合法赋值。
	
	printArray(arrPointer,3);

	printf("arrPointer value %d\n", *(arrPointer[1] + 1));

	pointer = arr[2];//二维度数组首地址的下标赋值给指针变量，合法。

	printf("arr[2] %d\n", *pointer);

	pointer = arr;//无效，arr实际上是 指针数组 int (*arr_name)[], 编译器会报出Wroning来。

	printf("arr %d\n", *pointer);

	int** dp = NULL;

	dp = &pointer; //双重指针指向指针的地址。合法的。

	//dp = &arr;//不能直接将数组名称赋值给dp，arr实际上是 指针数组 int (*arr_name)[],不能将这个赋值给 **p。
	*dp = arr[2];//这个是合法的，可以通过双指针去访问了，这里需要注意数组越界的事情。

	printf("%d\n", **dp);

	printf("-----------------------------\n");

	int var = 1;

	const int var2 = 2;

	const int* p = &var2; //合法， const对象地址赋值给 const 指针。

	p = &var; //合法，非const 对象赋值给const指针。（）
	int* p2 = &var2;
	//不合法，使用非const的指针修改了const不可以修改对象的值。但是编译器不会报错， 但是结果是未定义的。
	printf("value is %d\n", *p2);
	*p2 = 0;
	printf("value is %d\n", *p2);

	printf("----------------------\n");

	const int **pxxx;

	int* p3;

	const int vade = 4;
	
	pxxx = &p3; //合法，非const指针的地址赋值给const指针。

	*pxxx = &vade; //二位指针指向一位指针变量的地址，并且都是const，合法。

	printf("value is %d\n", vade);

	*p3 = 9;//直接通过非const指针进行修改。

	printf("value is %d\n", vade);


	/*
	1
	----------------------------------
	5 2 0
	0 0 4
	1 2 3
	arrPointer value 0
	arr[2] 1
	arr 5
	1
	-----------------------------
	value is 2
	value is 0
	----------------------
	value is 4
	value is 9
	*/
}

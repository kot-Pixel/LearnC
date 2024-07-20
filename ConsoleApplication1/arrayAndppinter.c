#include <stdio.h>

void arrayAndPointer(void);

int arrayAsParam(int *q, int);

int arrayAsParam2(int a[], int);

int arrayParam3(int* start, int* end);

void arrayAndPointer() {

	int arr[10] = {1,2,3,4,5,10,6,45,7,9};

	int* ptr = arr;

	printf("%p\n", arr);
	printf("%p\n", arr);
	printf("%p\n", ptr);
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr);

	// 数组名就代表着数组第一个元素的地址，他是一个常量，可以作为一个右值而不能作为一个左值。当数组名称赋值给指针的时候那么这个时候，此指针变量就相当于指向数组的第一个元素。

	int i;

	for (i = 0; i < 10; i++)
	{
		//对数组名称做加法/减法操作的话表达后一个/前一个元素的地址。
		printf("%p ", arr + i);
	}
	
	printf(" ------------------------\n");

	for (i = 0; i < 10; i++)
	{
		//对已经指向数组元素的第一个数组元素来说也是这样理解， 指向后一个/前一个元素地址。
		printf("%p ", ptr + i);
	}

	//可以理解为数组名称就是一个指针，并且他是const arr_tyepe *的指针，那么 运算符号操作地址的时候和存在的数据类型的大小是存在关系的。
	//指针是将地址作为值，那么派生出值可以使用下面两种方式：

	printf(" ------------------------\n");

	for (i = 0; i < 10; i++)
	{
		//对已经指向数组元素的第一个数组元素来说也是这样理解， 指向后一个/前一个元素地址。
		printf("%d ", arr[i]);
	}


	printf("\n------------------------\n");

	for (i = 0; i < 10; i++)
	{
		//对已经指向数组元素的第一个数组元素来说也是这样理解， 指向后一个/前一个元素地址。
		//这里需要注意下，  + 操作符的优先级别是小于解引用操作的
		printf("%d ", *(ptr + i));
	}

	printf("\n------------------------\n");

	//这里可以数组和指针联系在一起进行考虑，就是说 []和*类似，都是将地址进行操作，取出对应地址的值。

	int *ptr2 = arr + 3; //不指向数组的第一个元素而是使用数组第4个元素地址。这里写成 arr[3]是不正确了， 因为[]相当于解引用了。

	printf("%d\n", *ptr2);

	printf("----------------------\n");


	int addSumResult = arrayAsParam(arr, 10);
	int addSumResult2 = arrayAsParam2(arr, 10);

	printf("addSumResult is %d \n", addSumResult);
	printf("addSumResult is %d \n", addSumResult2);

	//如果直接打印数组名的话那么会输出数组中所有元素的的字节值，输出指向他的指针还是指针自身的大小。
	printf("addSumResult is %lu \n", (sizeof ptr));
	printf("addSumResult is %lu \n", (sizeof arr));
	printf("addSumResult is %lu \n", (sizeof &arr[0]));

	printf("------------------------------\n");

	int addSumResult3 =  arrayParam3(arr, arr + 10);
	printf("addSumResult3 is %d \n", addSumResult3);
	
}



/* 
* 当数组作为参数传递的时候，函数的形参需要是一个指针或者是[]来进行声明都是正确的。
* 
* 下面两个都是正确的定义方式int [] 或者 int *都是正确的方式。	
*/

int arrayAsParam(int* pointer, int size) {
	int sum = 0;
	for (int i = 0; i < size ; i++)
	{
		sum += *(pointer + i);
	}
	return sum;
}

int arrayAsParam2(int pointer[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += pointer[i];
	}
	return sum;
}

int arrayParam3(int* start, int* end) {
	int sum = 0;

	while (start < end) {
		sum += *start;
		start += 1;
	}

	return sum;
}
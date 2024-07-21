#include<stdio.h>

int pointerOprator() {

	int c = 12;

	int varArray[10] = {4,1,4,7,85,3,5,6,3,5};

	int* p, * p2, * p3;

	//这里将地址赋值给指针变量。
	p = varArray;
	p2 = varArray + 2;
	p3 = &varArray[5];

	//这样是不被允许的，因为指针变量还没有（初始化）指向，现在的指针属于是野指针。
	//*p2 = 12;

	printf("p3 value is %d \n", *p3);

	printf("before p value is %d and address is %p\n", *p, p);

	//指针变量自增，可以看到地址变量并不是单纯 + 1, 而是变了 （1 * int）类型在系统占的字节数。可以看到目前int占了4个字节，所以
	//内存地址从A8到AC。
	/*
	before p value is 4 and address is 00000037BC15FAA8
	after p value is 1 and address is 00000037BC15FAAC
	*/
	p++;


	printf("after p value is %d and address is %p\n", *p, p);

	//虽然数组的名称代表的是地址，但是和函数名类似，是一个常量。属于一个左值，不能自增。
	//varArray++;

	printf("\n -------------------------\n");

	//这里可以看到 指针变量的数值运算。这里也可以看到地址相差 （5 * int占的字节数量）
	//经过运算的指针变量和&varArray[6]值是一样的。
	/*
	before p value is 1 and address is 00000030956FFA9C
	after p value is 5 and address is 00000030956FFAB0
	*/

	printf("before p value is %d and address is %p\n", *p, p);

	p = p + 5;

	printf("after p value is %d and address is %p\n", *p, p);
	printf("after p value is %d and address is %p\n", varArray[6], &varArray[6]);

	printf("\n -------------------------\n");

	p = varArray;

	p3 = varArray + 10 - 1;

	printf("p value is %d and address is %p\n", *p, p);
	printf("p3 value is %d and address is %p\n", *p3, p3);


	printf("\n -------------------------\n");

	printf("%d\n", p3 - p);

	//指针直接还存在关系运算符号。因为这里p3和p都是指向数组元素而数组元素是顺序存储的，所以可以使用到关系元素符号，但是其他的情况下是不能确定的。
	printf("%d\n", p3 > p);
	int* p4 = &c;
	printf("%d\n", p4 > p);
	return 0;
}

/*
 1.赋值操作/指针指向操作。
 	p = varArray;
	p2 = varArray + 2;
	p3 = &varArray[5];
	上述都是指针变量的赋值操作。

 2.指针的解引用操作。
	*p2 *p *p3 这些都是解引用。
*/
#include <stdio.h>

int charArrayAndpointer2();

int charArrayAndpointer2() {
	//使用char数组来赋值的时候这个时候需要在数组的最后一个value上加上\0来表明字符串的结束。
	//const char p[] = { '1', '2', '2' };
	//const char p[] = { '1', '2', '2', '\0'};
	//const char p2[10] = { '2','3', '4', '\0' , '\0' , '\0' };//后续都会被填充\0
	//puts(p2);

	//当把程序载入内存时，也载入了程序中的字符串。字符串存储在静态存储区（static memory）中。但是此时并不会给数组字符串数组分配内存。
	//char *pointer = "132456";
	//程序在开始运行时才会为该数组分配内存
	//char pointer2[] = "132456";
	//指针和数组的区别

	//数组名在之前数组那边可以了解到，他是一个常量而非一个变量，使用char 数组来表达也是类似。
	//pointer作为一个数组，他是一个左值。他无法进行赋值。
	//pointer2++;

	//直接使用指向字符串字面量的数组进行修改值是不行的，相当与直接修改 static memory 中字符串的内容。虽然数组表示法在初始化的时候重新赋值了一份
	//但是也是可以修改不会影响到静态内存区域里面的常量数据的。

	//可以理解字符串的字面量都是const修饰的数据，使用指针表示法的时候需要同样使用const指针而不是指针。


	//char *p33xxx = "MyWord";

	//*p33xxx = 'U';

	//这里修改静态内存区域了，Visual Stuio 直接就报错了。

	//puts("MyWord");

	char arr[10] = "MyWord";
	arr[0] = 'U';

	puts(arr);

	printf("%p\n", &"MyWord");
	printf("%p\n", arr);

	/*
		UyWord
		00007FF6646FAC24
		000000C9D013F878
	*/
	return -1;
}
#include<stdio.h>
#define STR "This is a string str"
void stringPuts(void);

void stringPuts(void) {
	//字符串字面量
	char* p = "This is a char pointer can express array";
	//字符串数组
	char array[] = "This is a array is pointer named";
	// puts 函数和printf()函数一样都是定义在的stdio.h下的函数，作用就是用来输出字符串并且自动的换行。
	puts(p);
	puts(array);
	puts(STR);
	puts("------------------\n");
	//字符串字面量存储在内存区域的只读区域的, 不能通过指针来修改字符串字面量值。
	//*(p + 1) = 't';
	//字符串数组是可以修改的，因为字符串数组初始化的的时候将字符串常量复制到的字符串数组当中了。
	array[0] = 't';
	puts(p);
	puts(array);
	puts(STR);
	puts("------------------\n");
	printf("%p\n", p);
	printf("%p\n", array);

	//字符串常量用双引号引起来的部分是字符串字面量的指针。"This is a char pointer can express array" 这一串是指向存储它的指针。
	printf("%p\n", &"This is a char pointer can express array");
	printf("%p\n", &"This is a array is pointer named");

	//上面两个%p都是有效的，都是反映出字符串字面量指针的地址，并且需要注意的是，这些指针都是chat const类型的，是不可以赋值的。
	//使用指针的时候直接将地址赋值给char *p了(这个时候就产生了const赋值给非const了)， 使用数组的时候进行了复制。

	/*
	This is a char pointer can express array
	This is a array is pointer named
	This is a string str
	------------------

	This is a char pointer can express array
	this is a array is pointer named
	This is a string str
	------------------

	00007FF74170ADE0
	000000C9B6F1FBE8
	00007FF74170ADE0
	00007FF74170AE10
	*/

	// "dsadsads" 字面量就是代表存储字面量的地址。
	printf("%p %s %c", "2aaaa", "wwwww", *"dsadsads");
}
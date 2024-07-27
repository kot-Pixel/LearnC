#include<stdio.h>

void stringArray();

void stringArray() {

	//使用数组指针来表示字符串数组。
	char  *stringPointerArray[] = {
		"Hello World",
		"ChatGpt",
		"Android Studio",
		"Java Eclipse",
	};

	char stringArray[4][20] = {
		"Just do it", "come and go", "let it go", "please don't go"
	};


	for (size_t i = 0; i < 4; i++)
	{
		printf("%s \t %s \n", stringPointerArray[i] , stringArray[i]);
	}
	/*
	Hello World      Just do it
	ChatGpt          come and go
	Android Studio   let it go
	Java Eclipse     please don't go
	32       80
	*/

	//这两个大小是不一样的，字符串使用二位数组去描述的话，占用空间的大小是 （最长的字符串 * 个数）
	//很显然，使用数组指针去描述字符串数组相对空间占用比较好。
	printf("%llu \t %llu \n", sizeof(stringPointerArray), sizeof(stringArray));

}
#include <stdio.h>

void tt(void);

void charArrayAndpointer() {
	//使用char数组来赋值的时候这个时候需要在数组的最后一个value上加上\0来表明字符串的结束。
	//const char p[] = { '1', '2', '2' };
	const char p[] = { '1', '2', '2', '\0'};
	const char p2[10] = { '2','3', '4', '\0' , '\0' , '\0' };//后续都会被填充\0
	puts(p2);

	//
	const char *pointer = "132456";
	const char pointer[] = "132456";
}
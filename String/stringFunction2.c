#include<stdio.h>
#include<string.h>
void strLenTest2(void);

void strLenTest2() {
	char* str = "A";
	char* str2 = "F";
	char* str3 = "AA";

	//这里不能直接对比指针的值，如果想对比字符串的值就会需要使用strcmp函数。
	printf("str cmp2 result %d\n", str != str2);

	//使用strcmp函数来对字符串数组/指针进行比较。返回值等于 0，表示两个字符串下相等。返回值 1，表示字符串参数1是大于参数2，返回负值代表的，字符串参数2是大于字符串参数2.
	int cmp2 = strcmp(str2, str3);
	printf("str cmp2 result %d\n", cmp2);
	
	//strcmp函数会依次去判断字符串中每一个字符的的大小。下面字符串长度是不相等，相等于前面\0（空字符）和后面 s 进行判断。
	printf("str cmp2 result %d\n", strcmp("apple", "apples"));
	printf("str cmp2 result %d\n", strcmp("a", "Z"));

	//strncmp函数会存在参数去对比字符串中前n个字符串的长度大小。这里判断a和az，并且只判断前1个字符。
	printf("str cmp2 result %d\n", strncmp("a", "aZ", 1));

	char str4[10];
	char *p = strcpy_s(str4,10, str3);
	//strcpy_s是不会返回指针的。打印返回的x会出现问题的
	puts(str4);
	//puts(p);
	
	//下面对于没有分配内存空间字符串的copy肯定是错误的，仅仅声明指针变量是不能分配内存。
	//char *str5;
	//strcpy_s(str5, 10, str3);
	//puts(str5);
	
	char str5[10] = "17899";
	//不能将字符串拷贝到数组的下标开始的数组当中了。
	//strcpy_s(str5 + 3, 10, str3);
	puts(str5);

	//使用strncpy来判断拷贝的个数，最后指定为9.最多拷贝9个字符。
	char str6[10];
	strncpy_s(str6, 10,"q123456789", 9);
	puts(str6);

	//格式化字符串sprintf()的使用方式，非safe的方式已经废弃掉了。第一个参数是存储数组字符串的数组，第二个就是格式化的字符串，后续都是跟着需要格式化的字符串。
	char allStrl[100];

	sprintf_s(allStrl, 100 ,"aaaaaaaaaaaallllll %s, %d, %f", "wdf", 192, 0.86);

	puts(allStrl);
}
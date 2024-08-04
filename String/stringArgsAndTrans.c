#include<stdio.h>
#include<stdlib.h>

void test(void);

void trans() {
	//char s[100];
	//sprintf_s(s,100 ,"获取到args参数的个数为%d", argc);
	//下面就是传递参数全部打印。
	/*
		//LearnC.exe do hello world
		打印为：
		LearnC.exe
		do
		hello
		world
		main function read args from args
		默认的情况下：参数之间的间隔默认使用空格来进行空格的的，当然也可以使用""来将字符串完整作为参数。

		//LearnC.exe "do hello world"
		打印为：
		LearnC.exe
		do hello world
	*/
	//for (size_t i = 0; i < argc; i++)
	//{
		//puts(agrs[i]);
	//}
	printf("main function read args from args\n");

	//使用atoi函数, 可以将数值字符串转换为int类型的数字。此函数定义在stdlib当中。
	/*
	LearnC 1541wx
	main function read args from args
	args param is 1541

	当然 如果传递进来的字符串就不是一个数值字符串的话，那么就是会返回0.
	LearnC dwadwa
	main function read args from args
	args param is 0
	*/
	//int intArgs = atoi(agrs[1]);

	/*
		atol可以将字符串转换为long类型的数据。
		atof可以将字符串转换为double类型的数据。

		LearnC 123 121212 5.121111
		main function read args from args
		args param is 123
		args param is
		args param is 5.12
	*/
	//long long lValue = atoll(agrs[2]);

	//double flValue = atof(agrs[3]);

	//printf("args param is %d\n", intArgs);
	//printf("args param is %ll\n", lValue);
	//printf("args param is %0.2f\n", flValue);

	printf(" - - - - - - - - - - -");
	/*
	 atol/atoi 这些函数都是不安全的 不对输入字符串进行处理。产生异常时候只能自己处理。
	 strtol()函数会将字符串转化成为Int值，并且存在三个参数，第一个参数就是等待处理的字符串，第二参数是指针变量，指向等待之后处理完成的字符串。
	 第三个参数是进制. 10进制/16进制都可以。
	*/
	const char* str = "1234569Heek";
	char* p = NULL;
	int oo = strtol(str, &p, 10);

	printf("strtold value is %d %s %d\n", oo, p, *p);
	puts(p);
}
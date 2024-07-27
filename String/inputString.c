#include<stdio.h>

void inputStr(void);

void inputStr() {
	char* p = NULL;
	//This function or variable may be unsafe. Consider using scanf_s instead. 

	//这里直接想向p指针输入值，发现不可以直接通过scanf直接向char指针进行输入。
	//scanf("%s", p);


	char arr[10];

	//gets()函数会将读取输入直到遇到空行，遇到空行之后丢弃这个空行，然后在字符串结尾增加空字符串\0.
	//也就是如果数组的长度是10的话，那么通过gets输入到数组当中去的时候，只能输入9个字符，最后一个字符需要增加\0.
	//运行结果：
	/*
		123456789
		123456789
		那么数组中存储的是个字符就是1 2 3 4 5 6 7 8 9 \0,一共十个字符。注意使用gets()去读取的时候不会在结尾自动加上\n(换行)
	*/

	gets(arr);

	//一旦输入的字符个数超过开始定义的数组最大长度的时候，那么就会出现错误。输入：124567890，加上自动附上\0一共十一个字符便会出现越界的问题。
	//使用gets()，他无法检查数组是否装得下输入行。

	puts(arr);


	printf("-----------\n");

	//为了避免出现超出内存区域的问题，gets函数由于安全等等原因不使用，而使用新的函数fgets() / fputs()来输入和输出。
	//fgets()相对gets()来说来说主要是使用方式的变化，存在三个参数，第一个参数即函数名称，第二参数是读取最大的字符的个数。第三个是读取字符的来源。
	//这里输入数据会存储到arr数组中，并且最多存储（n - 1）个字符。和get一样，最终也是会附加空字符到数组的最后面。但是如果在 （n - 1）换行的话
	//那么fgets()也是会将\n作为字符存储到数组当中去，这一点和gets()不一样，gets会直接丢弃。第三个参数就是的标准的输入stdin.
	fgets(arr, 10, stdin);

	puts(arr);

	printf("puts invoke end\n");

	//fputs()和puts()也存在一定的区别，fputs()第一个参数是char 数据的来源，第二参数是输出到哪里，这里定义成stdout了。
	fputs(arr,stdout);

	//fgets()是会返回一个char类型的指针， 如果读取正常的话，那么它一般和参数1指向的是一个地址。
	// 如果函数读到文件结尾，它将返回一个特殊的指针：空指针（null pointer）。该指针保证不会指向有效的数据，所以可用于标识这种特殊情况。

	printf("fputs invoke end\n");

	printf("start printf fgets() funtion invoke\n");

	
	//这里可以实现读取无限制读取输入的功能，并且可以远远的超出的10的个数，其实本质上是多次读取而不是超过9个字符的限制。输入
	//都被缓存在stdin中了，通过多次循环的读取fputs()才实现读取.

	while (fgets(arr, 10, stdin) != NULL && arr[0] != '\0') {
		fputs(arr, stdout);
	}
	
	/*
	dsadsadsadsadsadsadsa
	dsadsadsadsadsadsadsa
	-----------
	123456789wdfwdf
	123456789
	puts invoke end
	123456789fputs invoke end
	start printf fgets() funtion invoke
	wdfwdf  //如果后面跟随scanf 其他类型的数据的话就会产生崩溃。
	*/

	//为什么要丢弃过长输入行中的余下字符。这是因为，输入行中多出来的字符会被留在缓冲区中，
	//成为下一次读取语句的输入。例如，如果下一条读取语句要读取的是double类型的值，就可能导致程序崩溃。丢弃输入行余下的字符保证了读取语句与键盘输入同步。
}
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 10

void strLenTest(void);

char* returnFirst(char [], int);

char* s_gets(char str[], int n);

void strLenTest() {
	char str[] = "hello please input str length";
	char str4[MAX_LENGTH];
	size_t length = strlen(str);
	printf("length of string is %llu \n", length);

	char *p = returnFirst(str, 9);
	puts(p);

	puts("------------------------------");

	char *str2[MAX_LENGTH];
	char *str3[3];

	char* p2 = NULL;
	char* p3 = NULL;
	char* p4 = NULL;

	//fgets(str2, MAX_LENGTH ,stdin);

	//fputs(str2, stdout);
	p2 = s_gets(str2, 10);
	puts("------------------------------");
	fputs(p2, stdout);
	//
	p3 = s_gets(str3, 3);
	puts("------------------------------");
	fputs(p3, stdout);
	puts("-------------strcat-----------------");
	//strcat会做字符串的拼接，将p3拼接到p2上，但是strcat之前和gets类似。他是不安全的，所以
	//现在strcat已经不推荐，需要使用的strcat_s来做字符串的处理。但是strcat_s第二个参数是第一个字符数组的长度，有效避免了越界。
	//第二个参数不应该超过字符串的总长度。
	//strcat_s(p2,8,p3);
	//fputs(p2, stdout);
	//fputs(p3, stdout);

	//strncat。strcat()函数无法检查第1个数组是否能容纳第2个字符串。如果分配给第1个数组的空间不够大，多出来的字符溢出到相邻存储单元时就会出问题。
	//使用strncat的最后一个参数表明凭借字符串的数量。下面指定concat的最大字符个数是为2.当然，strncat也是不安全的。


	//该函数把p3指向的字符串拷贝至篇指向的字符串末尾。p3字符串的第1个字符将覆盖p2字符串末尾的空字符。该函数返回s1。
	char * px = strncat_s(p2, 10, p3, 2);
	fputs(p2, stdout);
	printf("\n");
	fputs(p3, stdout);
	fputs(px, stdout);
}

char * returnFirst(char str[], int n) {
	//strlen会返回字符串的长度。
	size_t length = strlen(str);
	if (n > length) 
		return str;
	else 
		str[n] = '\0';
	return str;
}

char * s_gets(char str[], int n) {
	char *p = fgets(str, n, stdin);
	
	int index = 0;

	if (p != NULL) {
		while (p[index] != '\n' && p[index] != '\0') {
			index += 1;
		}

		if (p[index] == '\n') {
			p[index] = '\0';
		} else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}

	return p;
}
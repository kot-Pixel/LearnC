#include<stdio.h>
#include<stdlib.h>

void test(void);

void trans() {
	//char s[100];
	//sprintf_s(s,100 ,"��ȡ��args�����ĸ���Ϊ%d", argc);
	//������Ǵ��ݲ���ȫ����ӡ��
	/*
		//LearnC.exe do hello world
		��ӡΪ��
		LearnC.exe
		do
		hello
		world
		main function read args from args
		Ĭ�ϵ�����£�����֮��ļ��Ĭ��ʹ�ÿո������пո�ĵģ���ȻҲ����ʹ��""�����ַ���������Ϊ������

		//LearnC.exe "do hello world"
		��ӡΪ��
		LearnC.exe
		do hello world
	*/
	//for (size_t i = 0; i < argc; i++)
	//{
		//puts(agrs[i]);
	//}
	printf("main function read args from args\n");

	//ʹ��atoi����, ���Խ���ֵ�ַ���ת��Ϊint���͵����֡��˺���������stdlib���С�
	/*
	LearnC 1541wx
	main function read args from args
	args param is 1541

	��Ȼ ������ݽ������ַ����Ͳ���һ����ֵ�ַ����Ļ�����ô���ǻ᷵��0.
	LearnC dwadwa
	main function read args from args
	args param is 0
	*/
	//int intArgs = atoi(agrs[1]);

	/*
		atol���Խ��ַ���ת��Ϊlong���͵����ݡ�
		atof���Խ��ַ���ת��Ϊdouble���͵����ݡ�

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
	 atol/atoi ��Щ�������ǲ���ȫ�� ���������ַ������д��������쳣ʱ��ֻ���Լ�����
	 strtol()�����Ὣ�ַ���ת����ΪIntֵ�����Ҵ���������������һ���������ǵȴ�������ַ������ڶ�������ָ�������ָ��ȴ�֮������ɵ��ַ�����
	 �����������ǽ���. 10����/16���ƶ����ԡ�
	*/
	const char* str = "1234569Heek";
	char* p = NULL;
	int oo = strtol(str, &p, 10);

	printf("strtold value is %d %s %d\n", oo, p, *p);
	puts(p);
}
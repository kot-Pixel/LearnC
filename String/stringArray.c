#include<stdio.h>

void stringArray();

void stringArray() {

	//ʹ������ָ������ʾ�ַ������顣
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

	//��������С�ǲ�һ���ģ��ַ���ʹ�ö�λ����ȥ�����Ļ���ռ�ÿռ�Ĵ�С�� ������ַ��� * ������
	//����Ȼ��ʹ������ָ��ȥ�����ַ���������Կռ�ռ�ñȽϺá�
	printf("%llu \t %llu \n", sizeof(stringPointerArray), sizeof(stringArray));

}
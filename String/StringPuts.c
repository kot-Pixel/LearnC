#include<stdio.h>
#define STR "This is a string str"
void stringPuts(void);

void stringPuts(void) {
	//�ַ���������
	char* p = "This is a char pointer can express array";
	//�ַ�������
	char array[] = "This is a array is pointer named";
	// puts ������printf()����һ�����Ƕ����ڵ�stdio.h�µĺ��������þ�����������ַ��������Զ��Ļ��С�
	puts(p);
	puts(array);
	puts(STR);
	puts("------------------\n");
	//�ַ����������洢���ڴ������ֻ�������, ����ͨ��ָ�����޸��ַ���������ֵ��
	//*(p + 1) = 't';
	//�ַ��������ǿ����޸ĵģ���Ϊ�ַ��������ʼ���ĵ�ʱ���ַ����������Ƶ����ַ������鵱���ˡ�
	array[0] = 't';
	puts(p);
	puts(array);
	puts(STR);
	puts("------------------\n");
	printf("%p\n", p);
	printf("%p\n", array);

	//�ַ���������˫�����������Ĳ������ַ�����������ָ�롣"This is a char pointer can express array" ��һ����ָ��洢����ָ�롣
	printf("%p\n", &"This is a char pointer can express array");
	printf("%p\n", &"This is a array is pointer named");

	//��������%p������Ч�ģ����Ƿ�ӳ���ַ���������ָ��ĵ�ַ��������Ҫע����ǣ���Щָ�붼��chat const���͵ģ��ǲ����Ը�ֵ�ġ�
	//ʹ��ָ���ʱ��ֱ�ӽ���ַ��ֵ��char *p��(���ʱ��Ͳ�����const��ֵ����const��)�� ʹ�������ʱ������˸��ơ�

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

	// "dsadsads" ���������Ǵ���洢�������ĵ�ַ��
	printf("%p %s %c", "2aaaa", "wwwww", *"dsadsads");
}
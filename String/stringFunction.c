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
	//strcat�����ַ�����ƴ�ӣ���p3ƴ�ӵ�p2�ϣ�����strcat֮ǰ��gets���ơ����ǲ���ȫ�ģ�����
	//����strcat�Ѿ����Ƽ�����Ҫʹ�õ�strcat_s�����ַ����Ĵ�������strcat_s�ڶ��������ǵ�һ���ַ�����ĳ��ȣ���Ч������Խ�硣
	//�ڶ���������Ӧ�ó����ַ������ܳ��ȡ�
	//strcat_s(p2,8,p3);
	//fputs(p2, stdout);
	//fputs(p3, stdout);

	//strncat��strcat()�����޷�����1�������Ƿ������ɵ�2���ַ���������������1������Ŀռ䲻���󣬶�������ַ���������ڴ洢��Ԫʱ�ͻ�����⡣
	//ʹ��strncat�����һ����������ƾ���ַ���������������ָ��concat������ַ�������Ϊ2.��Ȼ��strncatҲ�ǲ���ȫ�ġ�


	//�ú�����p3ָ����ַ���������ƪָ����ַ���ĩβ��p3�ַ����ĵ�1���ַ�������p2�ַ���ĩβ�Ŀ��ַ����ú�������s1��
	char * px = strncat_s(p2, 10, p3, 2);
	fputs(p2, stdout);
	printf("\n");
	fputs(p3, stdout);
	fputs(px, stdout);
}

char * returnFirst(char str[], int n) {
	//strlen�᷵���ַ����ĳ��ȡ�
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
#include<stdio.h>
#include<string.h>
void strLenTest2(void);

void strLenTest2() {
	char* str = "A";
	char* str2 = "F";
	char* str3 = "AA";

	//���ﲻ��ֱ�ӶԱ�ָ���ֵ�������Ա��ַ�����ֵ�ͻ���Ҫʹ��strcmp������
	printf("str cmp2 result %d\n", str != str2);

	//ʹ��strcmp���������ַ�������/ָ����бȽϡ�����ֵ���� 0����ʾ�����ַ�������ȡ�����ֵ 1����ʾ�ַ�������1�Ǵ��ڲ���2�����ظ�ֵ����ģ��ַ�������2�Ǵ����ַ�������2.
	int cmp2 = strcmp(str2, str3);
	printf("str cmp2 result %d\n", cmp2);
	
	//strcmp����������ȥ�ж��ַ�����ÿһ���ַ��ĵĴ�С�������ַ��������ǲ���ȣ������ǰ��\0�����ַ����ͺ��� s �����жϡ�
	printf("str cmp2 result %d\n", strcmp("apple", "apples"));
	printf("str cmp2 result %d\n", strcmp("a", "Z"));

	//strncmp��������ڲ���ȥ�Ա��ַ�����ǰn���ַ����ĳ��ȴ�С�������ж�a��az������ֻ�ж�ǰ1���ַ���
	printf("str cmp2 result %d\n", strncmp("a", "aZ", 1));

	char str4[10];
	char *p = strcpy_s(str4,10, str3);
	//strcpy_s�ǲ��᷵��ָ��ġ���ӡ���ص�x����������
	puts(str4);
	//puts(p);
	
	//�������û�з����ڴ�ռ��ַ�����copy�϶��Ǵ���ģ���������ָ������ǲ��ܷ����ڴ档
	//char *str5;
	//strcpy_s(str5, 10, str3);
	//puts(str5);
	
	char str5[10] = "17899";
	//���ܽ��ַ���������������±꿪ʼ�����鵱���ˡ�
	//strcpy_s(str5 + 3, 10, str3);
	puts(str5);

	//ʹ��strncpy���жϿ����ĸ��������ָ��Ϊ9.��࿽��9���ַ���
	char str6[10];
	strncpy_s(str6, 10,"q123456789", 9);
	puts(str6);

	//��ʽ���ַ���sprintf()��ʹ�÷�ʽ����safe�ķ�ʽ�Ѿ��������ˡ���һ�������Ǵ洢�����ַ��������飬�ڶ������Ǹ�ʽ�����ַ������������Ǹ�����Ҫ��ʽ�����ַ�����
	char allStrl[100];

	sprintf_s(allStrl, 100 ,"aaaaaaaaaaaallllll %s, %d, %f", "wdf", 192, 0.86);

	puts(allStrl);
}
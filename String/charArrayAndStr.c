#include <stdio.h>

void tt(void);

void charArrayAndpointer() {
	//ʹ��char��������ֵ��ʱ�����ʱ����Ҫ����������һ��value�ϼ���\0�������ַ����Ľ�����
	//const char p[] = { '1', '2', '2' };
	const char p[] = { '1', '2', '2', '\0'};
	const char p2[10] = { '2','3', '4', '\0' , '\0' , '\0' };//�������ᱻ���\0
	puts(p2);

	//
	const char *pointer = "132456";
	const char pointer[] = "132456";
}
#include<stdio.h>

int pointerOprator() {

	int c = 12;

	int varArray[10] = {4,1,4,7,85,3,5,6,3,5};

	int* p, * p2, * p3;

	//���ｫ��ַ��ֵ��ָ�������
	p = varArray;
	p2 = varArray + 2;
	p3 = &varArray[5];

	//�����ǲ�������ģ���Ϊָ�������û�У���ʼ����ָ�����ڵ�ָ��������Ұָ�롣
	//*p2 = 12;

	printf("p3 value is %d \n", *p3);

	printf("before p value is %d and address is %p\n", *p, p);

	//ָ��������������Կ�����ַ���������ǵ��� + 1, ���Ǳ��� ��1 * int��������ϵͳռ���ֽ��������Կ���Ŀǰintռ��4���ֽڣ�����
	//�ڴ��ַ��A8��AC��
	/*
	before p value is 4 and address is 00000037BC15FAA8
	after p value is 1 and address is 00000037BC15FAAC
	*/
	p++;


	printf("after p value is %d and address is %p\n", *p, p);

	//��Ȼ��������ƴ�����ǵ�ַ�����Ǻͺ��������ƣ���һ������������һ����ֵ������������
	//varArray++;

	printf("\n -------------------------\n");

	//������Կ��� ָ���������ֵ���㡣����Ҳ���Կ�����ַ��� ��5 * intռ���ֽ�������
	//���������ָ�������&varArray[6]ֵ��һ���ġ�
	/*
	before p value is 1 and address is 00000030956FFA9C
	after p value is 5 and address is 00000030956FFAB0
	*/

	printf("before p value is %d and address is %p\n", *p, p);

	p = p + 5;

	printf("after p value is %d and address is %p\n", *p, p);
	printf("after p value is %d and address is %p\n", varArray[6], &varArray[6]);

	printf("\n -------------------------\n");

	p = varArray;

	p3 = varArray + 10 - 1;

	printf("p value is %d and address is %p\n", *p, p);
	printf("p3 value is %d and address is %p\n", *p3, p3);


	printf("\n -------------------------\n");

	printf("%d\n", p3 - p);

	//ָ��ֱ�ӻ����ڹ�ϵ������š���Ϊ����p3��p����ָ������Ԫ�ض�����Ԫ����˳��洢�ģ����Կ���ʹ�õ���ϵԪ�ط��ţ�����������������ǲ���ȷ���ġ�
	printf("%d\n", p3 > p);
	int* p4 = &c;
	printf("%d\n", p4 > p);
	return 0;
}

/*
 1.��ֵ����/ָ��ָ�������
 	p = varArray;
	p2 = varArray + 2;
	p3 = &varArray[5];
	��������ָ������ĸ�ֵ������

 2.ָ��Ľ����ò�����
	*p2 *p *p3 ��Щ���ǽ����á�
*/
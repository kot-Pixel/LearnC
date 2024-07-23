/*
	�˽�ָ��ļ����ԡ�
*/
#include <stdio.h>

void printArray(int(*p)[3], int);

void compatibilityOfPointer(void);


void printArray(int(*p)[3], int z)
{
	for (size_t i = 0; i < z; i++)
	{
		for (size_t j = 0;  j < 3;  j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}

void compatibilityOfPointer()
{
	int varInt = 1;
	double dbVar = 0.5F;

	//dbVar = varInt;

	//��������е�ʱ�������ֵ������ȷ�ģ�����ָ���������ͨ�ı����������ָ�����͵ļ�������ԱȽ��ϸ�
	//printf("%f", dbVar);

	//������int *
	int* pointer = &varInt;
	double* dbPointer = &dbVar;
	//������벻�ᱨ���ˣ��� int *��ָ�븳ֵ��double *Ҳ���ᱨ��, �������ᱨ����
	dbPointer = pointer;

	printf("%d\n", *dbPointer);
	printf("----------------------------------\n");

	int arr[3][3] = {
		{ [1] = 2, [0] = 5},{[2] = 4}, {1,2,3}
	};

	int(*arrPointer)[3] = arr; //ָ�������ָ��һ����ά�����飬�Ϸ���ֵ��
	
	printArray(arrPointer,3);

	printf("arrPointer value %d\n", *(arrPointer[1] + 1));

	pointer = arr[2];//��ά�������׵�ַ���±긳ֵ��ָ��������Ϸ���

	printf("arr[2] %d\n", *pointer);

	pointer = arr;//��Ч��arrʵ������ ָ������ int (*arr_name)[], �������ᱨ��Wroning����

	printf("arr %d\n", *pointer);

	int** dp = NULL;

	dp = &pointer; //˫��ָ��ָ��ָ��ĵ�ַ���Ϸ��ġ�

	//dp = &arr;//����ֱ�ӽ��������Ƹ�ֵ��dp��arrʵ������ ָ������ int (*arr_name)[],���ܽ������ֵ�� **p��
	*dp = arr[2];//����ǺϷ��ģ�����ͨ��˫ָ��ȥ�����ˣ�������Ҫע������Խ������顣

	printf("%d\n", **dp);

	printf("-----------------------------\n");

	int var = 1;

	const int var2 = 2;

	const int* p = &var2; //�Ϸ��� const�����ַ��ֵ�� const ָ�롣

	p = &var; //�Ϸ�����const ����ֵ��constָ�롣����
	int* p2 = &var2;
	//���Ϸ���ʹ�÷�const��ָ���޸���const�������޸Ķ����ֵ�����Ǳ��������ᱨ�� ���ǽ����δ����ġ�
	printf("value is %d\n", *p2);
	*p2 = 0;
	printf("value is %d\n", *p2);

	printf("----------------------\n");

	const int **pxxx;

	int* p3;

	const int vade = 4;
	
	pxxx = &p3; //�Ϸ�����constָ��ĵ�ַ��ֵ��constָ�롣

	*pxxx = &vade; //��λָ��ָ��һλָ������ĵ�ַ�����Ҷ���const���Ϸ���

	printf("value is %d\n", vade);

	*p3 = 9;//ֱ��ͨ����constָ������޸ġ�

	printf("value is %d\n", vade);


	/*
	1
	----------------------------------
	5 2 0
	0 0 4
	1 2 3
	arrPointer value 0
	arr[2] 1
	arr 5
	1
	-----------------------------
	value is 2
	value is 0
	----------------------
	value is 4
	value is 9
	*/
}

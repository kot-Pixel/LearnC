#include<stdio.h>

void printArray(const int* p, int size_t);
void printArray2(int* p, int size_t);

void printArray(const int* p, int size_t) {

	int i;
	for (i = 0; i < size_t; i++)
	{
		printf("%d ", *(p + i));
	}

	printf("\n");
}

void printArray2(int* p, int size_t) {

	int i;
	for (i = 0; i < size_t; i++)
	{
		printf("%d ", *(p + i));
		*(p + i) = i;
	}
	printf("\n");
	for (i = 0; i < size_t; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
}



int pointConst() {

	const int arr[10] = { 1466,121,454,4547,198,557,255,754,733,11 };
	int arr2[10] = { 1466,121,454,4547,198,557,255,754,733,11 };

	//����ʧ�ܵģ�arr����ʹ��const���������ˣ���ʾ�����鲻�ܹ����и�ֵ��

	//arr[0] = 1;

	const int* p = arr;
	 int const * p = arr;

	//*p = 0;��ֵʧ��, const int ��ʾ���ܽ��и�ֵ�ġ����ǿ������޸ĵ�ַ�ġ�

	//arr2[0] = 2;//���Ը�ֵ arr2�����޸ġ�

	p = arr + 3;//����ǺϷ��ģ�const int ��ʾ���ܸ�ֵ���ǿ������¸���ַ��

	//const / ��const ���ε����鶼�Ǵ��θ�const����ġ�
	//printArray(arr2, 10);
	//printArray(arr, 10);

	/*
	1466 121 454 4547 198 557 255 754 733 11
	0 1 2 3 4 5 6 7 8 9
	*/
	//��Ȼ��const���鸳ֵ���ݲ�������const����Ļ����������ϲ��ᱨ�����ǽ����δ����ġ�
	printArray2(arr, 10);
	//printArray2(arr2, 10);

	

	return 0;
}
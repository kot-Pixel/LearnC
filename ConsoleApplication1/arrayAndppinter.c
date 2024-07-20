#include <stdio.h>

void arrayAndPointer(void);

int arrayAsParam(int *q, int);

int arrayAsParam2(int a[], int);

int arrayParam3(int* start, int* end);

void arrayAndPointer() {

	int arr[10] = {1,2,3,4,5,10,6,45,7,9};

	int* ptr = arr;

	printf("%p\n", arr);
	printf("%p\n", arr);
	printf("%p\n", ptr);
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr);

	// �������ʹ����������һ��Ԫ�صĵ�ַ������һ��������������Ϊһ����ֵ��������Ϊһ����ֵ�����������Ƹ�ֵ��ָ���ʱ����ô���ʱ�򣬴�ָ��������൱��ָ������ĵ�һ��Ԫ�ء�

	int i;

	for (i = 0; i < 10; i++)
	{
		//�������������ӷ�/���������Ļ�����һ��/ǰһ��Ԫ�صĵ�ַ��
		printf("%p ", arr + i);
	}
	
	printf(" ------------------------\n");

	for (i = 0; i < 10; i++)
	{
		//���Ѿ�ָ������Ԫ�صĵ�һ������Ԫ����˵Ҳ��������⣬ ָ���һ��/ǰһ��Ԫ�ص�ַ��
		printf("%p ", ptr + i);
	}

	//�������Ϊ�������ƾ���һ��ָ�룬��������const arr_tyepe *��ָ�룬��ô ������Ų�����ַ��ʱ��ʹ��ڵ��������͵Ĵ�С�Ǵ��ڹ�ϵ�ġ�
	//ָ���ǽ���ַ��Ϊֵ����ô������ֵ����ʹ���������ַ�ʽ��

	printf(" ------------------------\n");

	for (i = 0; i < 10; i++)
	{
		//���Ѿ�ָ������Ԫ�صĵ�һ������Ԫ����˵Ҳ��������⣬ ָ���һ��/ǰһ��Ԫ�ص�ַ��
		printf("%d ", arr[i]);
	}


	printf("\n------------------------\n");

	for (i = 0; i < 10; i++)
	{
		//���Ѿ�ָ������Ԫ�صĵ�һ������Ԫ����˵Ҳ��������⣬ ָ���һ��/ǰһ��Ԫ�ص�ַ��
		//������Ҫע���£�  + �����������ȼ�����С�ڽ����ò�����
		printf("%d ", *(ptr + i));
	}

	printf("\n------------------------\n");

	//������������ָ����ϵ��һ����п��ǣ�����˵ []��*���ƣ����ǽ���ַ���в�����ȡ����Ӧ��ַ��ֵ��

	int *ptr2 = arr + 3; //��ָ������ĵ�һ��Ԫ�ض���ʹ�������4��Ԫ�ص�ַ������д�� arr[3]�ǲ���ȷ�ˣ� ��Ϊ[]�൱�ڽ������ˡ�

	printf("%d\n", *ptr2);

	printf("----------------------\n");


	int addSumResult = arrayAsParam(arr, 10);
	int addSumResult2 = arrayAsParam2(arr, 10);

	printf("addSumResult is %d \n", addSumResult);
	printf("addSumResult is %d \n", addSumResult2);

	//���ֱ�Ӵ�ӡ�������Ļ���ô���������������Ԫ�صĵ��ֽ�ֵ�����ָ������ָ�뻹��ָ������Ĵ�С��
	printf("addSumResult is %lu \n", (sizeof ptr));
	printf("addSumResult is %lu \n", (sizeof arr));
	printf("addSumResult is %lu \n", (sizeof &arr[0]));

	printf("------------------------------\n");

	int addSumResult3 =  arrayParam3(arr, arr + 10);
	printf("addSumResult3 is %d \n", addSumResult3);
	
}



/* 
* ��������Ϊ�������ݵ�ʱ�򣬺������β���Ҫ��һ��ָ�������[]����������������ȷ�ġ�
* 
* ��������������ȷ�Ķ��巽ʽint [] ���� int *������ȷ�ķ�ʽ��	
*/

int arrayAsParam(int* pointer, int size) {
	int sum = 0;
	for (int i = 0; i < size ; i++)
	{
		sum += *(pointer + i);
	}
	return sum;
}

int arrayAsParam2(int pointer[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += pointer[i];
	}
	return sum;
}

int arrayParam3(int* start, int* end) {
	int sum = 0;

	while (start < end) {
		sum += *start;
		start += 1;
	}

	return sum;
}
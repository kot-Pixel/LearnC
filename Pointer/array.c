#include <stdio.h>
#define ARR_INDEX 10

void arrayTest(void);

void arrayTest() {
	printf("invoke array Test\n");

	/*
		�������index�ĸ������������ʼ����ʱ�� {} ������������ʱ����ô���ʱ������index�ͻḳֵΪ0.
		arr�����ǿ��Ը�ֵ�ģ��������ʹ�� const �����������ʱ��˵���������ǲ����Ը��ĵģ����ʱ��arr[0] = 1;���Ƶĸ�ֵ��ʽ���ǲ������ˡ�
	*/
	int arr[ARR_INDEX] = { 1,2,3,4,5,6,7 };

	int i,j;

	for (i = 0; i < ARR_INDEX; i++)
	{
		printf("%d - - - - - index: %d \n", arr[i], i);

		arr[i] = i;
	}
	printf("array printf agine \n");

	for (i = 0; i < ARR_INDEX; i++)
	{
		printf("%d - - - - - index: %d \n", arr[i], i);
	}
	
	printf("---------------------\n");

	/*
		����Ҳ����ʹ�ô� [index]��ָ��index�±��ض���ֵ��
	*/
	int arr2[] = {1,2,3,[2] = 4 };

	for (i = 0; i < ARR_INDEX; i++)
	{
		printf("%d - - - - - index: %d \n", arr2[i], i);
	}

	printf("---------------------\n");

	//int arr3[ARR_INDEX];

	//arr3 = arr2;

	//��������˸�ֵ����һ�����鸳ֵ�������һ�����������ϡ��������֪��arr3�������Ʊ����ϲ��Ǳ�������һ����ֵ��������ֵ��ֱ��ȥ��ֵ�ǲ���ȷ�ġ�

	//for (i = 0; i < ARR_INDEX; i++)
	//{
	//	printf("%d - - - - - index: %d \n", arr3[i], i);
	//}

	int x = 3, o = 10;
	int rainArray[3][10] = {
		{1,2,3,4,5,6,7,8,9,10},
		{1,2,3,4,5,6,7,8,9,10},
		{1,2,3,4,5,6,7,8,9,10},
	};

	int rainArray2[3][10] = {
		{1,2}, {1, [4] = 5}
	};

	//�����ǳ�ʼ����ά����ķ�ʽ��

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < o; j++)
		{
			printf("%d ", rainArray2[i][j]);
		}

		printf("\n");
	}
	
	return 0;


}
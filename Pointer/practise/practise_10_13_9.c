/*
��дһ��������ʾ�û�����3������ÿ��������5��double���͵����������û�����ȷ����Ӧ�������������ֵ���ݣ����ó���Ӧ����������񡣡���
a�����û���������ݴ洢��3��5�������С���
b������ÿ�飨5�������ݵ�ƽ��ֵ����
c�������������ݵ�ƽ��ֵ����
d���ҳ���15�������е����ֵ����
e����ӡ���
*/
#include<stdio.h>

void programe(void);

double arrage(double *, int);

double arrage2(double (*)[5], int);

void programe(void)
{

	double p[3][5];

	for (size_t i = 0; i < 3; i++)
	{
		printf("please input the %llu data\n", i+1);

		for (size_t j = 0; j < 5; j++)
		{
			int x = scanf("%lf", *(p + i) + j);

			printf("[%llu][%llu]intput down\n", i + 1, j + 1);
		}
	}

	printfDoubleArray(p, 3);

	for (size_t i = 0; i < 3; i++)
	{
		printf("value is : %0.2f\n", arrage(p[i], 5));
	}

	printf("value is222 : %0.2f\n", arrage2(p, 3));
}

double arrage2(double(*p)[5], int size)
{
	double sum = 0.0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			sum += (*(p + i))[j];
		}
	}
	return sum / (size * 5);
}

double arrage(double *p, int size)
{
	double sum = 0.0;
	for (size_t i = 0; i < size; i++)
	{
		sum += *(p + i);
	}
	return (sum / size);
}

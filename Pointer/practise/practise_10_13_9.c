/*
编写一个程序，提示用户输入3组数，每组数包含5个double类型的数（假设用户都正确地响应，不会输入非数值数据）。该程序应完成下列任务。　　
a．把用户输入的数据存储在3×5的数组中　　
b．计算每组（5个）数据的平均值　　
c．计算所有数据的平均值　　
d．找出这15个数据中的最大值　　
e．打印结果
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

#include<stdio.h>
/*
��дһ�����򣬳�ʼ��һ��double���͵Ķ�ά���飬ʹ�ñ����ϰ2�е�һ�����������Ѹ������е����ݿ�������һ����ά������
����Ϊ��ά��������������飬���Կ���ʹ�ô���һά����Ŀ������������������е�ÿ�������飩��
*/

void copyMultipleArray(double (*)[10], double (*)[10], int);

void copyMultipleArray(double (*target)[10], double (*source)[10], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		copy_arr(target[i], source[i], 10);
	}
}
/*
int main() {
	printf("pointer practise\n");

	double source[3][10] = {
		{
			[0] = 1.5,[6] = 3.2,[9] = 4.55
		},
		{
			[6] = 15.5,[1] = 33.12,[8] = 124.55
		},
		{
			[2] = 21.5,[6] = 387.2,[7] = 114.55
		},
	};

	double target[3][10];
	printfDoubleArray(source, 3);
	copyMultipleArray(target, source, 3);
	printf("\n");
	printfDoubleArray(target, 3);
}

pointer practise
1.50 0.00 0.00 0.00 0.00 0.00 3.20 0.00 0.00 4.55
0.00 33.12 0.00 0.00 0.00 0.00 15.50 0.00 124.55 0.00
0.00 0.00 21.50 0.00 0.00 0.00 387.20 114.55 0.00 0.00

1.50 0.00 0.00 0.00 0.00 0.00 3.20 0.00 0.00 4.55
0.00 33.12 0.00 0.00 0.00 0.00 15.50 0.00 124.55 0.00
0.00 0.00 21.50 0.00 0.00 0.00 387.20 114.55 0.00 0.00
*/

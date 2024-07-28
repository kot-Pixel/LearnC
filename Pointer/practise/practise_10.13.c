/*
2����дһ�����򣬳�ʼ��һ��double���͵����飬Ȼ��Ѹ���������ݿ�����3�����������У���main()��������4�����飩��
ʹ�ô������ʾ���ĺ������е�1�ݿ�����ʹ�ô�ָ���ʾ����ָ������ĺ������е�2�ݿ�����
��Ŀ����������Դ�������ʹ�������Ԫ�ظ�����Ϊǰ���������Ĳ�������3��������Ŀ����������Դ��������ָ��Դ�������һ��Ԫ�غ����Ԫ�ص�ָ�롣

double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[5];
double target2[5];
double target3[5];
copy_arr(target1, source, 5);
copy_ptr(target2, source, 5);

copy_ptrs(target3, source, source + 5);
*/
#include<stdio.h>

void copy_arr(double[], double[], int);

void copy_ptr(double *, double*, int);

void copy_ptrs(double[], double[], double*);

void copy_arr(double target[], double source[], int size)
{
	for (int i = 0; i < size; i++)
	{
		target[i] = source[i];
	}
}

void copy_ptr(double *target, double *source, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(target + i) = *(source + i);
	}
}

void copy_ptrs(double target[], double source[], double *end)
{
	int i = 0;
	while (source + i < end) {
		target[i] = source[i++];
	}
}

/*
int main() {
	printf("pointer practise\n");

	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];
	double target3[5];
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);

	printfArray(target1, 5);
	printfArray(target2, 5);
	printfArray(target3, 5);

	return 0;
}

���н����
1.10 2.20 3.30 4.40 5.50
1.10 2.20 3.30 4.40 5.50
1.10 2.20 3.30 4.40 5.50
*/

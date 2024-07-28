/*
2．编写一个程序，初始化一个double类型的数组，然后把该数组的内容拷贝至3个其他数组中（在main()中声明这4个数组）。
使用带数组表示法的函数进行第1份拷贝。使用带指针表示法和指针递增的函数进行第2份拷贝。
把目标数组名、源数组名和待拷贝的元素个数作为前两个函数的参数。第3个函数以目标数组名、源数组名和指向源数组最后一个元素后面的元素的指针。

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

运行结果：
1.10 2.20 3.30 4.40 5.50
1.10 2.20 3.30 4.40 5.50
1.10 2.20 3.30 4.40 5.50
*/

/*
把double类型数组中的数据倒序排列，并在一个简单的程序中测试该函数。
*/
#include<stdio.h>

void revertDoubleArray(double *p, double *p2);

void revertDoubleArray(double* p, double* p2)
{
	double tmp = 0.0;
	while (p < p2) {
		tmp = *p;
		*p = *p2;
		*p2 = tmp;
		p += 1;
		p2 -= 1;
	}
}

/*
int main() {
	printf("pointer practise\n");

	double arr2[10] = {
		85.41,
		4.4741,
		715.851,
		145.4,
		15.54,
		17956.99,
		185.541,
		4444.714,
		44.12621,
		1441.0
	};
	printfArray(arr2,10);
	revertDoubleArray(arr2, arr2 + 9);
	printfArray(arr2, 10);
	return 0;
}
pointer practise
85.41 4.47 715.85 145.40 15.54 17956.99 185.54 4444.71 44.13 1441.00
1441.00 44.13 4444.71 185.54 17956.99 15.54 145.40 715.85 4.47 85.41
*/

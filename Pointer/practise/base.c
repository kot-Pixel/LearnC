#include "base.h"
#include<stdio.h>

void printfArray(double *arrayName, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%.2f ", *(arrayName + i));
	}
	printf("\n");
}


void printfArrayInt(int* arrayName, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", *(arrayName + i));
	}
	printf("\n");
}

void printfDoubleArray(double(*arrayName)[5], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			printf("%.2f ", *(*(arrayName + i) + j));
		}
		printf("\n");
	}
}

#include<stdio.h>
#include"base.h"

int main() {
	//programe();
	int* ptr;
	int torf[2][2] = { 12, 14, 16 };
	ptr = torf[1];
	printf("%d", *ptr);
}
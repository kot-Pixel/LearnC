#include <stdio.h>
#define VALUE 12

void printfAddress(int , int );
void pointerArgs(int *, int *);

int functionPointerTest() {

	int sourceA, sourceB;
	sourceA = 1;
	sourceB = 2;
	
	printf("sourceA addres is %p \n", &sourceA);
	printf("sourceB addres is %p \n", &sourceB);

	printf("sourceA value is %d \n", sourceA);
	printf("sourceB value is %d \n", sourceB);
	printfAddress(sourceA, sourceB);

	printf("--------------------------\n");
	printf("sourceA value is %d \n", sourceA);
	printf("sourceB value is %d \n", sourceB);
	pointerArgs(&sourceA, &sourceB);

	printf("after sourceA value is %d \n", sourceA);
	printf("after sourceB value is %d \n", sourceB);
	return 0;
}

void printfAddress(int a, int b) {
	printf("a addres is %p \n", &a);
	printf("b addres is %p \n", &b);
}

void pointerArgs(int* p1, int* p2) {
	printf("p1 addres is %p \n", p1);
	printf("p2 addres is %p \n", p2);

	int tmp = *p1;

	*p1 = *p2;

	*p2 = tmp;

	printf("after sw p1 addres is %p \n", p1);
	printf("after sw p2 addres is %p \n", p2);
}
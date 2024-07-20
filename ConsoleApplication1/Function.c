#include <stdio.h>
#define VALUE 12

void add(int, int);

int main() {
	
	//int sourceA, sourceB;
	//sourceA = 1;
	//sourceB = 2;
	//printf("add function invoke\n");
	//printf("sourceA value is %d, sourceB b value is %d \n", sourceA, sourceB);
	//add(sourceA, sourceB);
	//add(1, 432.2F);

	//printf("sourceA value is %d, sourceB b value is %d \n", sourceA, sourceB);

	//functionPointerTest();

	//arrayTest();

	//arrayAndPointer();

	pointerOprator();
	return 0;
}

void add(int a, int b) {
	printf("param a value is %d, param b value is %d \n", a, b);
	int tmp = b;
	b = a;
	a = tmp;
	printf("param a value is %d, param b value is %d \n", a, b);
}
#include<stdio.h>

int main()
{
    int var = 0;
    int *ptr = &var;
    int **doublePointr = &ptr;
    int **doublePointr2 = NULL;

    doublePointr2 = doublePointr;

    printf("var value is %d\n", var);
    printf("ptr value is %d\n", *ptr);
    printf("ptr value is %p\n", ptr);
    printf("double ptr value is %p\n", *doublePointr);
    printf("double ptr value is %d\n", **doublePointr);
    printf("double ptr2 value is %p\n", *doublePointr2);
    printf("double ptr2 value is %d\n", **doublePointr2);
    printf("size of pointer %lu \n", sizeof(ptr));
    printf("size of double pointer %lu\n", sizeof(doublePointr));
}
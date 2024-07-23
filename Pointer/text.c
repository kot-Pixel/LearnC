#include<stdio.h>
#include<stdint.h>
#include<limits.h>

int main() 
{
    unsigned char c = 200;

    printf("%d\n", c);

    int16_t int8 = 200;

    printf("%d\n", int8);
    
    printf("%d\n", UCHAR_MAX);

    double x = 10.1E2;

    printf("%fs\n", x);

    int floatValue = 3.25F;

    printf("%d\n", floatValue);

    printf("long int sizeof is: %zu\n", sizeof(long int));

    printf("int sizeof is: %zu\n", sizeof(int));

    printf("long long int sizeof is: %zu\n", sizeof(long long int));

    return 0;
}

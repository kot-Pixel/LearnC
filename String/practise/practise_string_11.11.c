/*
*编写一个通过命令行运行的程序计算幂。第1个命令行参数是double类型的数，作为幂的底数，第2个参数是整数，作为幂的指数。
*/

int main(int argc, char * argv[]) {
    printf("__argc size is %d \n", argc);
    double mater = atof(argv[1]);
    int x = atoi(argv[2]);
    double result = pow(mater, x);
    printf("pow result %0.2f \n", result);
}

/*
__argc size is 3
pow result 4.93
*/

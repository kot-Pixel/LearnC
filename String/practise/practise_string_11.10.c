/*
* 编写一个程序，反序显示命令行参数的单词。例如，命令行参数是see you later，该程序应打印later you see。
*/

/*
  多出来的参数指向自己exe
*/
int main(int argc, char * argv[]) {
    printf("__argc size is %d \n", argc);
    for (int i = argc - 1; i >= 1; i--) {
        puts(argv[i]);
    }
}

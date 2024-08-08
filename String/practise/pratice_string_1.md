11.12　复习题

1. 没有\0作为结尾，会出现越界的问题。

2. 
```
#include <stdio.h>
    int main(void)
    {
    char note[] = "See you at the snack bar.";
    char *ptr;

    ptr = note;
    puts(ptr);
    puts(++ptr);
    note[7] = '\0';
    puts(note);
    puts(++ptr);
    return 0;
    }
    //将会输出
    See you at the snack bar.
    ee you at the snack bar.
    See you
    e you
```

3. 
```c++
#include <stdio.h>
#include <string.h>
int main(void)
{
     char food [] = "Yummy";
     char *ptr;
    
     ptr = food + strlen(food);
     while (--ptr >= food)
          puts(ptr);
     return 0;
}
输出： y
      my
      mmy
      ummy
      Yummy
```

4. 
```c++
#include <stdio.h>
#include <string.h>
int main(void)
{
     char goldwyn[40] = "art of it all ";
     char samuel[40] = "I read p";
     const char * quote = "the way through.";

     strcat(goldwyn, quote);
     strcat(samuel, goldwyn);
     puts(samuel);
     return 0;
}
输出：  I read part of it all the way through.
```
5. 
```c++
#include <stdio.h>
char *pr(char *str)
{
     char *pc;

     pc = str;
     while (*pc)
          putchar(*pc++);
     do {
          putchar(*pc--);
         } while (pc - str);
     return (pc);
}
x = pr("Ho Ho Ho!");
输出： Ho Ho Ho!!oH oH oH
      x的类型是char *的指针对象。
      x的值是H.
      两个表达式的优先级不一样， *--pc 指针变量向前动一下。 --*pc, 这个表示将对应的字符减1.
      Ho Ho Ho!!oH oH o (因为*和--自增++自减这些都是相同级别的运算符)。
      如果pr()函数的参数是空字符串，会怎样？会一直输出知道内存中遇到\0。
      两个while，第一个while是向后遍历，第二个while是从后向前遍历。
      ""字符串修改成"\0" / " "
      
```

6.
```c++
char sign = '$';
 1个字节。1个字节。2个字节.
```

7.
```c++
#include <stdio.h>
#include <string.h>
#define M1 "How are ya, sweetie? "
char M2[40] = "Beat the clock.";
char * M3 = "chat";
int main(void)
{
     char words[80];
     printf(M1);
     puts(M1);
     puts(M2);
     puts(M2 + 1);
     strcpy(words, M2);
     strcat(words, " Win a toy.");
     puts(words);
     words[4] = '\0';
     puts(words);
     while (*M3)
          puts(M3++);
     puts(--M3);
     puts(--M3);
     M3 = M1;
     puts(M3);
     return 0;
}

输出：
How are ya, sweetie? How are ya, sweetie? 
Beat the clock.
eat the clock.
Beat the clock. Win a toy.
Beat
chat
hat
at
t
t
at
How are ya, sweetie? 
```
8.
```c++
#include <stdio.h>
int main(void)
{
     char str1 [] = "gawsie"; 
     char str2 [] = "bletonism";
     char *ps;
     int i = 0;
     for (ps = str1; *ps != '\0'; ps++) {
          if (*ps == 'a' || *ps == 'e')
               putchar(*ps);
          else
               (*ps)--;
          putchar(*ps);
          }
     putchar('\n');
     while (str2[i] != '\0') {
          printf("%c", i % 3 ? str2[i] : '*');
          ++i;
          }
     return 0;
}
faavrhee
*le*on*sm
b - 98 - *
l - 97 + 11 = 108 - l
e - 97 + 5 = 112 - *
t - 97 + 17 = 114 - *
o - 97 + 14 = 111 - o
n - 97 + 13 = 110 - *
i - 97 + 8 = 105 - i
s - 97 + 18 = 115 - *
m - 97 + 12 = 109 - *
```

10.strlen()函数接受一个指向字符串的指针作为参数，并返回该字符串的长度。请编写一个这样的函数。
```c++
int strlen_x(char *p) {
    int result = 0;
    while (*(p + result++) != '\0') {

    }
    return result - 1;
}
```

11.设计一个函数，接受一个指向字符串的指针，返回指向该字符串第1个空格字符的指针，或如果未找到空格字符，则返回空指针。
```c++
char * get_blank(char *p) {
    int result = 0;
    char *result_p = NULL;
    while (*(p + result++) != ' ') {
    }
    if (*(p + result) != '\0') {
        result_p = p + result - 1;
    }
    return result_p;
}
```


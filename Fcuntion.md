# 函数

## 基本说明

涉及到函数的部分主要有三个部分

1. 函数原型(function prototype): 告诉编译器函数的类型。

2. 函数定义(function definition): 明确的定义函数实现了什么功能。

3. 函数调用(function call): 表明在此执行函数调用。

```c
//对应上述函数的原型。
void add(int, int);

int main() {
	
	int sourceA, sourceB;
	sourceA = 1;
	sourceB = 2;
	printf("add function invoke\n");
	printf("sourceA value is %d, sourceB b value is %d \n", sourceA, sourceB);
	//function call, 函数调用。
    add(sourceA, sourceB);
	printf("sourceA value is %d, sourceB b value is %d \n", sourceA, sourceB);
	return 0;
}

//function definition, 进行了函数了定义。
void add(int a, int b) {
	printf("param a value is %d, param b value is %d \n", a, b);
	int tmp = b;
	b = a;
	a = tmp;
	printf("param a value is %d, param b value is %d \n", a, b);
}

/*
add function invoke
sourceA value is 1, sourceB b value is 2
param a value is 1, param b value is 2
param a value is 2, param b value is 1
sourceA value is 1, sourceB b value is 2
*/

```

### 函数形式参数

上述定义add函数的时候，定义了`a`和`b`，这两个参数都是形式参数，在函数调用的时候会进行值传递。形式参数本质上被函数中定义的变量， 实际参数是主调函数赋给被调函数的具体值。这个具体值的表现可以是常量、变量或甚至是更复杂的表达式。 无论实际参数是何种形式都要被求值， 然后该值被拷贝给被调函数相应的形式参数。

```c
#include <stdio.h>
#define VALUE 12
void add(int, int);
int main() {
	
	int sourceA, sourceB;
	sourceA = 1;
	sourceB = 2;
	printf("add function invoke\n");
	printf("sourceA value is %d, sourceB b value is %d \n", sourceA, sourceB);
	add(VALUE + sourceA, sourceB);
	printf("sourceA value is %d, sourceB b value is %d \n", sourceA, sourceB);

	return 0;
}

void add(int a, int b) {
	printf("param a value is %d, param b value is %d \n", a, b);
	int tmp = b;
	b = a;
	a = tmp;
	printf("param a value is %d, param b value is %d \n", a, b);
}

/*
add function invoke
sourceA value is 1, sourceB b value is 2
param a value is 13, param b value is 2
param a value is 2, param b value is 13
sourceA value is 1, sourceB b value is 2
*/

```

可以看到add函数进行对a,b变量交换，但是不会影响到调用函数的传递的变量，就是因为函数定义是一个形式参数，在调用函数的时候进行传递的是值传递。

下面这个例子，可以更加表明形式参数调用的时候， 调用函数和被调用函数是值传递。

```c
#include <stdio.h>
#define VALUE 12
void printfAddress(int , int );
int functionPointerTest() {
	int sourceA, sourceB;
	sourceA = 1;
	sourceB = 2;
	
	printf("sourceA addres is %p \n", &sourceA);
	printf("sourceB addres is %p \n", &sourceB);
	printfAddress(sourceA, sourceB);
	return 0;
}
void printfAddress(int a, int b) {
	printf("a addres is %p \n", &a);
	printf("b addres is %p \n", &b);
}
/*
sourceA addres is 000000CC9FD8F754
sourceB addres is 000000CC9FD8F774
a addres is 000000CC9FD8F730
b addres is 000000CC9FD8F738
*/
```

那如何使用函数来对传递的变量做一些变化呢，可以使用return赋值的方式，但是return仅仅只会返回一个值。另外可以使用指针pointer来作为参数。

# 指针

## &取地址运算符号

&(变量)可以将变量的地址取出来，上面代码的 &a 和 &b 就分别将 a 和 b 的地址取出来并且使用%p来进行打印了。printfAddress函数进行打印的过程中，sourceA 的地址是： 000000CC9FD8F754， 函数变量a的地址是： 000000CC9FD8F730。

两个地址是不相等的，形式参数的函数调用的时候进行了值传递，也就是将存储在000000CC9FD8F754地址上的值复制到地址000000CC9FD8F730上了。函数定义中无论怎么对a变量做更改都不会影响到调用函数的变量。

值传递保证了函数变量之间的隔离，可以通过指针作为函数参数来做到函数调用改变调用函数中的变量.

```c
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
	printfAddress(sourceA, sourceB);
	printf("--------------------------\n");
	pointerArgs(&sourceA, &sourceB);
	return 0;
}

void printfAddress(int a, int b) {
	printf("a addres is %p \n", &a);
	printf("b addres is %p \n", &b);
}

void pointerArgs(int* p1, int* p2) {
	printf("p1 addres is %p \n", p1);
	printf("p1 addres is %p \n", p2);
}

/*
sourceA addres is 000000BB13EFFB54
sourceB addres is 000000BB13EFFB74
a addres is 000000BB13EFFB30
b addres is 000000BB13EFFB38
--------------------------
p1 addres is 000000BB13EFFB54
p1 addres is 000000BB13EFFB74

*/
```
pointerArgs 中 打印出来的地址和 functionPointerTest 函数变量的地址是相同的，那么对这指针变量进行操作的话也就可以对函数变量进行操作了。

其中需要解引用操作符号*来取出指针变量的值了。

```c
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

/*
sourceA addres is 000000446875FB34
sourceB addres is 000000446875FB54
sourceA value is 1
sourceB value is 2
a addres is 000000446875FB10
b addres is 000000446875FB18
--------------------------
sourceA value is 1
sourceB value is 2
p1 addres is 000000446875FB34
p2 addres is 000000446875FB54
after sw p1 addres is 000000446875FB34
after sw p2 addres is 000000446875FB54
after sourceA value is 2
after sourceB value is 1
*/
```

普通变量把值作为基本量， 把地址作为通过&运算符获得的派生量， 而指针变量把地址作为基本量， 把值作为通过*运算符获得的派生量.




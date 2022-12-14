// 局部变量_全局变量
#include <stdio.h>
// 全局变量
int sum  = 0;
int x;
double d;
float f;
char ch;

void test(){
    int age = 1;
    age++;
    sum ++;
    printf("age=%d\n",age); // 2
    printf("sum=%d\n",sum); // 1
}
//int main(int argc, const char *argv[]) {
int main_3_5(int argc, const char *argv[]) {
    test();
    printf("sum=%d\n",sum); // 0
    
    // 7、可以定义1个和全局变量的名字相同的局部变量。
    // 局部变量
    int sum  = -9;
    printf("sum=%d\n",sum); // 0
    test();
    
    // 默认值 - 局部变量
    int result;
    printf("result=%d\n",result); // 随机数
    
    // 默认值 - 全局变量
    printf("int=%d\n",x); // 0
    printf("double=%lf\n",d); // 0.000000
    printf("float=%f\n",f); // 0.000000
    printf("char=%c\n",ch); // '\0'
    
    
    return 0;
}

/**
 1 变量的种类
     局部变量：定义在函数内部
     全局变量：定义在函数外部的变量。直接定义在源文件下面。
 
 2、 全局变量和局部变量的相同点、不同点
 相同：都是变量。都是在内存中开辟一块空间来存储数据。
 
 不同：
 1）声明的位置不同。局部变量声明在函数内部。全局变量声明在函数外部。
 2）作用域不同。
     a) 局部变量。只能在当前函数的内部访问。
     b) 全局变量。从这个定义全局变量的地方开始，后面的所有函数都可以访问这个全局变量。
     一般情况下，全局变量定义在最顶上。#include 下面
 3） 默认值不同
     a）局部变量
     声明1个局部变量，如果没有设初始值，那么这个局部变量中有值，是1个垃圾值。是1个随机数。
 
     b）全局变量
     声明1个全局变量，如果没有设初始值，它的初始默认值是0，
     int        0
     double 0.000000
     float     0.000000
     char      '\0'
     
     '\0' 表示1个不可见的字符，它的ASCII码是0
 
 4）创建和回收的时间不同。
    a）局部变量
    CPU执行声明局部变量的那句话的时候，才会在内存中声明。
    当作用域结束后，就被自动回收。
    
    b)全局变量
    程序一旦启动，就在内存中创建全局变量。
    程序结束的时候，全局变量才会被回收。
 
 5、 全局变量的特点：
     1）程序一启动就被创建，直到程序结束才会被回收。
     无论在哪个函数中，访问局部变量，访问的是同1个，
     具有共享性。

     局部变量，每次调用函数都会重新声明1个，函数结束的时候局部变量就会被回收。

    2）什么时候需要把1个数据定义为全局变量。
     想要被多个函数访问。
 
 
 6、 函数如果不被调用，函数内部的代码是不会被执行的。
 
 7、可以定义1个和全局变量的名字相同的局部变量。
    这时，从函数内部从定义同名局部变量开始后面访问这个变量，访问的是局部变量。
    但是一般不这样定义，也不建议这样写，因为可读性不好，容易搞晕。
 */

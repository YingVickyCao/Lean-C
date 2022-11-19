#include <stdio.h>

//int main(int argc, const char *argv[]) {
int main_5_1(int argc, const char *argv[]) {
    // (1)
    int score = 85;
    if (score > 60) {
        printf("及格\n"); // invloked
        printf("Good\n");
    }; // 这个分号可以不加，默认也是不加

    //  (2)
    int num = 50;
    if (num + 10 > 0) { // good
        printf("哈哈\n");
    }
    if (num + 10) { // bad,没有什么意义，
        printf("哈哈\n");
    }

    // (3)
    if (1) {
        printf("is always invoked");
    }

    if (0) {
        printf("is never invoked");
    }

    return 0;
}
/**
 
 一、顺序结构
 从上到下，一句一句执行。
 每一行代码都要执行。
 
 二、分支结构
 1 比较表达式和逻辑表达式，称为条件表达式
     条件表达式，描述的是1个或多个条件。

     仅仅是为了判断？ 根据不同的结果做出不同的反应。

 2 IF 结构
    1) 作用：在代码世界中，有1段 代码，不是非要执行。而是在满足某个条件时才执行，否则不执行。

 2) 语法：
     if (条件表达式){
        执行代码;
     }

    条件表达式 :比较表达式 或 逻辑表达式

 3 注意事项
    1) 关于分号
     一条语句的后面，要写1个分号（；），1个分号代表指令的结束。
     CPU在识别指令的时候，如何判断指令并结束，用分号为基准。

     绝大多数情况下，每1条语句代表1个指令，所以每条语句的后面要跟1个分号。

     IF结构是1个语法块，它的范围是从{开始到}结束。右大括号代表语法的结束。所以，一般情况下，IF结构块需要加加分号，因为 } 就代表语法块的结束。
     就算要加，也应该加在}的后面。

     2) IF后面 ()中可以添加任意表达式.
     虽然
     0 代表假，
     非0代表真。
     虽然也这样也可以写，但是这样没有什么意义，一般情况下，还是写条件表达式。

     (3) 永真和永假
     if(1) 永远成立
     if(0) 永远不成立

     (4) 保持正确的代码缩进 -> 可读性
     格式化快捷键 Ctrl + I
 */

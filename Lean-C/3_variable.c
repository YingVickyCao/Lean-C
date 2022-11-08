#include "stdio.h"

void set_int_value();
void set_float_value();
void set_double_value();
void set_char_value();
void use_variable();
void variable_tip();
void use_printf();
void prinf_int();
void prinf_double();
void auto_type_convert();

int main(int argc, const char* argv[]){
//int main_mark(int argc, const char* argv[]){
//    printf("Hello World\n");
//    set_int_value();
//    set_float_value();
//    set_double_value();
//    set_char_value();
//    use_variable();
//    variable_tip();
//    use_printf();
    auto_type_convert();
    return 0;
}

/**
 为int 赋值
 因为变量的类型是int，所以为int 赋值时，赋值的数据不能超过指定的范围

 a) 如果给定的数据太大，直接语法
 b) 如果为int 赋值1个小数，只会存储1个小数的整数部分。不会四舍五入。
 c) 如果给的数据超出范围并不多，虽然能运行，但是存储的是随机值（暂且这么认为）
 
 */
void set_int_value(){
    int num;
    num = 10;
    printf("%d\n",num); // 10
    
    // Compile error : Integer literal is too large to be represented in any integer type
//    num = 100000000000000000000000;
    
    num = 9.566;
    printf("%d\n",num); // 9
    
    // Warning : Implicit conversion from 'long' to 'int' changes value from 2200000000 to -2094967296
    num = 2200000000;
    printf("%d\n",num); // -2094967296
}

/**
 为float 赋值
 
 (1)浮点字面值默认是double类型
 (2)为float变量赋值的时候，赋值的小数后要加f
 (3)float只能保存精确保存有效位数不超过 7 位的小数。
 如果赋值的有效位数超过了 7 位，那么超出的部分不会精确保存。
 
 */
void set_float_value(){
    float f1;
    // 浮点字面值默认是double类型, 内存占据8个字节。虽然运行时的值是正确的，那么是12.12并没有超出float的范围。
    f1 = 12.12; // Depressed
    printf("%f\n",f1);
    
    // f表示12.12 是float 类型，内存占据4个字节
    f1 = 12.12f; // Recommended
    printf("%f\n",f1);
    
    // 只能精确保存12.12345（除了.,共7位），超出的部分，不能精确保存。打印出的最后7，刚好凑齐而已。
    f1 = 12.123456789f; // 12.123457
    printf("%f\n",f1);
    
    f1 = 1234567.123456789f;
    printf("%f\n",f1);  // TODO: 1234567.125000

    f1 = 12345678.123456789f;
    printf("%f\n",f1);  // TODO: 12345678.000000
}

/**
 为double 赋值
 
 double只能保存精确保存有效位数不超过16位的小数。
 如果赋值的有效位数超过了16位，那么超出的部分不会精确保存。
 */
void set_double_value(){
    double d;
    d = 12.12;
}

/**
 为char赋值

 (1)char 只能存储单个字符。
 (2)如果给的值太多，只能保存最后一个。
 (3)空格也是1个字符，所以，可以存储1个空格。
 (4) char 变量中无法存储中文。因为在C中。1个中文字符占三个字节。而1个char变量占一个字节。
 
 */
void set_char_value(){
    char ch;
    ch = 'a';
    printf("%c\n",ch);

    // Warning : Implicit conversion from 'int' to 'char' changes value from 1633837924 to 100
    ch = 'abcd';    // d
    printf("%c\n",ch);
    
    ch = ' ';    // 空格
    printf("%c\n",ch);
}

/**
 如何使用存储在变量中的数据呢？
 （1）想用的时候，直接写上变量的名字，就可以使用了
 （2）使用变量最常见的方式，是将变量的值输出。
 printf 函数输出变量的值。
 
 printf("格式控制字符传",变量列表);
 
 在格式控制字符串中，如果有地方要显示变量的值。那么就使用1个占位符来占位。
 输出的变量的类型不同，占位符是不一样的。
 int, %d
 float, %f, 默认输出小数点后面的6位
 double,%lf, 默认输出小数点后面的6位
 char, %c
 
 输出变量时，使用占位符和输出的变量类型不匹配，那么输出的结果就是错误的。
 
 输出多个变量时，依此写上要占位的变量
 （a）后面的变量一定要按照顺序来写，因为填占位符的时候，是根据顺序来占位的。否则就会混乱。
 （b）后面的变量的个数要和前面的占位符一致。如果没有变量填的就是随机值。
 */
void use_variable(){
    int num1=10;
    int num2=20;
    
    int result = num1+num2;
    printf("%d\n",result);  // 30
    
    printf("value of sum is result\n"); // value of sum is result
    
    // %d 表示这个变量不要原样输出，而是输出这个变量的值
    printf("value of sum is %d\n",result); // value of sum is 30
     
    float money = 100.12f;
    printf("I have %f CNY\n",money);    // I have 100.120003 CNY
    
    double treeHeight = 100.12;
    printf("The high tree is %lf tall\n",treeHeight);    // The high tree is 100.120000 tall
    
    char myChar;
    myChar = 'z';
    printf("This char value is %c\n",myChar);   // This char value is z
    
    
    // 1次输出多个变量
    printf("%f,%lf,%c\n",money,treeHeight, myChar);   // 100.120003,100.120000,z

    // 输出多个变量时，占位符与变量不对应也能运行，但是结果不正确。
    printf("%f,%lf,%c\n",myChar,money,treeHeight);   // 100.120003,100.120000,z

    // 输出多个变量时，少了参数也能运行，但是结果不正确。
    printf("%f,%lf,%c\n",money);   // 100.120003,0.000000, 
    
    // 输出多个变量时，少了参数也能运行，但是结果不正确。
    printf("%f,%c，%lf\n",money);   // 100.120003,，10.997869 
}

/**
 
 使用变量时，注意事项：
1） 有double，为何还要有float？
double 的空间是float 空间的两倍。如果数据本身有效位数不超过7位，那么使用double 才存储会比较浪费。
2) 可以在声明变量的同时位变量赋值。也就是 初始化
 初始化，比先声明后赋值，更高效
3) 可批量声明多个相同类型的变量
 前提是类型相同的变量
 4） 赋值语句的规范
 赋值号两边留空格
 
 5) 垃圾值
 声明1个变量，如果没有为这个变量赋值，这种变量中是有值的。该值是一个随机数。这个值叫垃圾值。值是不确定的。
 所以，为了保证程序不会出意想不到的问题，要求声明1个变量后，应该立即为这个变量赋值1个初始值。
 
 6) 变量可以重新赋值
 变量重新赋值，新值覆盖旧值，旧值消失。
 
 7) 为变量赋值时，把另一个变量的值设给它.
 变量之间的赋值原理：
 将源变量的值复制1份，将这个副本赋值给目标变量，但源变量的值还在。

 8) 使用变量之前，必须保证变量已经声明了
 
 9）同一个变量不允许重复定义。
 */

void variable_tip(){
    // 初始化
    int count = 0;
    
    // 先声明后赋值
    int score;
    score = 1;
    
    // 批量声明
    int num1, num2=8,num3=5;
    
    // 赋值语句的规范
    int num = 3;
    
    // 垃圾值
//    int year;    // not should
    int year = 0; // ok
    int next_year = year + 1;
    printf("%d\,%d\n",year,next_year); // 48,49
    
    // 变量可以重新赋值
    num  = 30;
    printf("%d\n",num); // 30
    
    
    // 为变量赋值时，把另一个变量的值设给它.
    int n1 = num;
    printf("%d\,%d\n",num,n1); // 30,30
}

/**
 prinft : 向控制台输出信息

 (1)int   %md  m 是整数，指定输出变量时占多少位.
 e.g., %5d,
 如果变量小于5位，不足用空格补齐。
 如果变量>=5位，实际有多少位就显示多少位

 e.g., %05d, 如果变量小于5位，不足用0补齐
 
 m为正数，前面补齐，
 m为负数，后面补齐

 (2)double  %.nlf 指定输出小数点后的位数
 (3)float  %.nf 指定输出小数点后的位数
 */
void use_printf(){
//    prinf_int();
    
    prinf_double();
}


void prinf_int()
{ // Int
    int num = 10;
    //10
    printf("%d\n",num);
    //   10
    printf("%5d\n",num); // %md
    int x = 123456789;
    // 123456789
    printf("%5d\n",x); // %md
    //10   XXX
    printf("%-5dXXX\n",num); // %md
    
    //00010
    printf("%05d\n",num);
    
    
}

void prinf_double(){
    // Double
    double d = 10.1234567890;
    // 10.123457
    printf("%lf\n",d); // Default 输出 6 位。 7 四舍五入后进位1
    
    // Double
    double d2 = 10.123456123;
    // 10.123456
    printf("%lf\n",d2); // Default 输出 6 位。 1 四舍五入是0，不进位，
    
    // 10.12
    printf("%.2lf\n",d); // 指定输出小数点后的2位
}


/**
 数据转换类型
 1 为变量赋值时，赋值的数据的数据类型，必须和变量的类型时一致的，否则就会出问题.
 为变量赋值时，赋值的数据的数据类型，和变量的类型不一致，这时C系统会将赋值的数据的类型 转换为 变量的类型，然后再赋值。
 这种情况叫做自动类型转换。
 
 有类型转换，C系统会多做一件事情
 
 2 变量是int
 （1）如果赋值的数据超出了int的范围，这时C系统会将数据转换为1个随机的int数据。
 （2）如果赋值的数据超出了int的范围太多，自动类型转换转不了，编译器直接报语法错误。
 （3）如果赋值的数据是1个浮点数，这时C系统会直接截取整数部分。
 
 3 变量是float类型
 (1)若赋值的数据是1个double类型，这时C系统将这个double类型的小数转换为float
 (1)若赋值的数据是1个int类型，这时C系统将这个int类型的小数转换为float
 
 4 变量是double类型
 (1)若赋值的数据是1个float类型，这时C系统将这个float类型的小数转换为double
 (1)若赋值的数据是1个int类型，这时C系统将这个int类型的小数转换为double
 
 4 变量是char类型
 ASCII码： 每个字符数据都有一个与之对应的整数，这个整数就叫做ASCII码
 不需要记忆，只需要记住3个
 `0` 49
 `A` 65
 `a` 97
 其他ASCII码都可以推出来，有规律。
 
 为char变量赋值的时候，可以直接赋值ASCII码。
 为char变量赋值一个整数时，实际上赋值的是以这个整数为ASCII码所对应的字符数据。
 */
void auto_type_convert(){
    // int
    int num = 22000000000;
    printf("%d\n",num); // 525163520
    
    // Error: compile error, integer literal is too large to be represented in any integer type
//    int num2 = 1122487898445564544211000400000000;
//    printf("%d\n",num2); // 12
    
    int num3 = 12.123;
    printf("%d\n",num3); // 12
    
    
    // float
    float f1 = 12.12; // double -> int
    float f2 = 12.12f; // 没有类型转换
    float f3 = 12; // int -> float
    
    // double
    double d1 = 12.12; // 没有类型转换
    double d2 = 12.12f; // float -> double
    double d3 = 12; // int -> double
    
    // char
    char ch1 = '0';
    char ch2 = 65;
    printf("%c\n",ch2); // A
    char ch3 = 'A';
    printf("%c\n",ch3); // A
    
    char ch4 = 65.9;
    printf("%c\n",ch4); // A
}

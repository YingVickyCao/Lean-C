// 进制之间的转换
#include <stdio.h>
int main(int argc, const char *argv[]) {
    // Examle 1
    // 二进制
    printf("%d\n",0b10);    // 2
    
    // Examle 2
    printf("%d\n",0b1010);  // 10
    
    // Examle 3
    printf("%d\n",0b10101); // 21
    
    // Examle 4
    // 八进制
    printf("%d\n",0116); // 78
    
    // Examle 5
    printf("%d\n",0342); // 226
    
    // Examle 6
    printf("%d\n",0b001011100110011); // 5939
    printf("%d\n",013463); // 5939
    
    // Example 7
    printf("%d\n",0134674); // 47548
    printf("%d\n",0b001011100110111100); // 47548
    printf("%o\n",0b001011100110111100); // 134674
    
    // Example 8
    printf("%0x\n",0b001011100110011); // 1733
    return 0;
}

/**
 1、基本概念
    数码：指的是每1位的数字
    数位：数码在这个数中的位置。从右到左，依次递增，从0开始
    基数：每一个数码可以有多少个数据来表示。
         基数，其实是指这个数的进制
    位权：数码 * 基数的数位次方
         任何数的0次方都是1。
 
     比如：二进制：
     10
     0 ： 数码是0，数位是0，位权是: 0 * 2^0 = 0
     1 ： 数码是1，数位是1，位权是: 1 * 2^1 = 2
 
 
 2、十进制转换为二进制
    除2取余法。将这个数除以2，直到余数为0或1。然后将最后1个商和所有余数倒序。
 
    10 -> 1010
 
 3、二进制转换为十进制
    加权法。将这个二进制的每个数码的位权相加。
 
    10101 每个数码的位权相加
    1 * 2^0 +  0* 2^1 + 1 * 2^2 +  0* 2^3 + 1 * 2^4 = 1 + 0 + 4 + 0 + 16 = 21
 
    二进制的位权：假如每个数码都是1
    0       1
    1       2
    2       4
    3       8
    4       16
    5       32
    6       64
    ...
 
 4、十进制转换为八进制
    除8取余法。
    78 => 116
 
 5、八进制转换为十进制
    加权法
    
    0342
    =>
    2 * 8^0 +  4* 8^1 + 3 * 8^2 +  0* 8^3 = 2 + 32 + 192  + 0 = 226

 6、二进制转换为八进制
    三合一法则。
    具体：
    将这个二进制从低到高位每三组分成1组，高位不够补0.
    将每1组转换为十进制。
    将每1组的十进制连起来，就是这个二进制对应的八进制。
    
    0b001011100110011
    =>
    001     011     100     110     011
    1         3         4          6        3
    =>13463
 
 
 7、八进制转换为二进制
    一拆三
    将这个八进制的每个数码拆为1个三位的二进制，把这些二进制连起来。
 
    134674
    =>
    1        3          4            6          7           4
    001    011      100        110      111     100
 
 8、二进制转换为十六进制
    四合一法则。
     具体：
     将这个二进制从低到高位每四组分成1组，高位不够补0.
     将每1组转换为十六进制。
     将每1组的十六进制连起来，就是这个二进制对应的十六进制。
 
    0b001011100110011
    =>
    (补00) 001        0111        0011       0011
    1                    7                 3            3
    => 1733
 
 */

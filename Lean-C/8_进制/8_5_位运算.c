// 位运算
#include <stdio.h>
int main(int argc, const char *argv[]) {
    // 按位与 &
    printf("%d\n",3&2); // 2
    printf("%d\n",-3&4); // 4
    printf("%d\n",-3&-4); // -4
    
    if((10 & 1) == 0){
        printf("10 is 偶数\n");
    }
    
    if((8 & 1) == 0){
        printf("8 is 偶数\n");
    }
    if((9 & 1) == 1){
        printf("9 is 奇数\n");
    }
    if((7 & 1) == 1){
        printf("7 is 奇数\n");
    }
    
    // 按位或 ｜
    printf("%d\n",3|2); // 3
    printf("%d\n",-3|4); // -3
    printf("%d\n",-3|-4); // -3
    
    // 按位取反 ~
    printf("%d\n",~3); // -4
    
    
    // 按位异或
    printf("%d\n",3 ^ 2); // 1
    
    int a = 3;
    int b = 2;
    printf("a=%d,b=%d\n",a,b); // a=3,b=2
    
    a = a ^ b;    // a = 3 ^ 2 = 1
    b = a ^ b;    // b = 1 ^ 2 = 3
    a = a ^ b;    // a = 1 ^ 3 = 2
    printf("a=%d,b=%d\n",a,b); // a=2,b=3
    
    return 0;
}

/**
 1、位运算
 指定是1个二进制数据的每一位来参与运算。
 位运算的前提：是这个数必须是1个二进制。

 注意：
1）、参与位运算的数是二进制的补码形式
2）、位运算的结果也是二进制的补码形式
 
 2、按位与 &
 参与（按位与）的两个二进制数的位，如果都是1，那么结果是1。只有1个位0，则结果是0
 
 
 3 & 2
 3的补码   ：00000000   00000000    00000000    00000011
 2的补码   ：00000000   00000000    00000000    00000010
 &------------------------------------------------------------------
          00000000   00000000    00000000    00000010       => 2
 
 -3 & 4
 -3的原码   ：10000000   00000000    00000000    00000011
 -3的反码   ：11111111   11111111    11111111    11111100
 -3的补码   ：11111111   11111111    11111111    11111101

 -3的补码   ：11111111   11111111    11111111    11111101
 4的补码   ：  00000000   00000000    00000000    00000100
 &------------------------------------------------------------------
           00000000   00000000    00000000    00000100       => 4
 
 -3 & -4
 -3的补码   ：11111111   11111111    11111111    11111101
 -4的原码   ： 10000000   00000000    00000000   00000100
 -4的反码   ： 11111111   11111111    11111111   11111011
 -4的补码   ： 11111111   11111111    11111111   11111100
 
 -3的补码   ：11111111   11111111    11111111   11111101
 -4的补码   ：11111111   11111111    11111111   11111100
 &------------------------------------------------------------------
          11111111   11111111    11111111    11111100   补码
          11111111   11111111    11111111    11111011    反码
          10000000   00000000    00000000    00000100   原码
 
 负数的补码->反码？ 符号位不变,-1
 负数的反码->原码？符号位不变，其他位取反
 
 任何数按位与1的结果是：是这个数的最低位。
 10 & 1
 
 00000000   00000000    00000000    00000001
 xxxxxxxx    xxxxxxxx     xxxxxxxx      xxxxxxxx
 ------------------------------------------------------------------
 00000000   00000000    00000000    00000000
 
 偶数的最低位一定是0.
 奇数的最低位一定是1.
 所以判断这个数是偶数还是奇数，只要用这个数按位与1就可以了。
 如果结果是1，则是奇数，如果结果是0，则为偶数。
 
 2、按位或 ｜
 参与（按位或）的两个二进制数的位，如果有一个是1，那么结果是1。只有都是1个位0，则结果为0
 3 & 2?
 3的补码   ：00000000   00000000    00000000    00000011
 2的补码   ：00000000   00000000    00000000    00000010
 ｜------------------------------------------------------------------
          00000000   00000000    00000000    00000011       => 3
 
 -3 & 4?
 -3的补码   ：11111111   11111111    11111111    11111101
 4的补码   ：  00000000   00000000    00000000    00000100
 |------------------------------------------------------------------
           11111111   11111111    11111111    11111101  补码
           11111111   11111111    11111111    11111100  反码
           10000000   00000000    00000000    00000011  原码=>-3
 
 
 -3的补码   ：11111111   11111111    11111111   11111101
 -4的补码   ：11111111   11111111    11111111   11111100
 |------------------------------------------------------------------
          11111111   11111111    11111111    11111101
 
 4、按位取反 ~
 单目运算符：将这个二进制数的每1位取反
 
 ~3
 
 3的补码   ：00000000   00000000    00000000    00000011
 ~------------------------------------------------------------------
          11111111   11111111    11111111    11111100  补码
          11111111   11111111    11111111    11111011  反码
          10000000   00000000    00000000    00000100  原码  => -4
 
 5、按位异或
 参与（按位或）的两个二进制数的位，相同为0，不同为1
 
 3 ^2
 
 3的补码：00000000   00000000    00000000    00000011
 2的补码：00000000   00000000    00000000    00000010
 ^------------------------------------------------------------------
         00000000   00000000    00000000    00000001   => 1
 
 交换两个变量的值可以用异或运算
 int a = 3;
 int b = 2;
 
 a = a ^ b;    // a = 3 ^ 2 = 1
 b = a ^ b;    // b = 1 ^ 2 = 3
 a = a ^ b;    // a = 1 ^ 3 = 2
 
 
 1 ^ 2
 00000000   00000000    00000000    00000001
 ^
 00000000   00000000    00000000    00000010
 ------------------------------------------------------------------
 00000000   00000000    00000000    00000011   => 3

 
 1 ^ 3
 1
 00000000   00000000    00000000    00000001
 ^
 00000000   00000000    00000000    00000011
 ------------------------------------------------------------------
 00000000   00000000    00000000    00000010   => 2
 */



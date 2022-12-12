//  二维数组

#include <stdio.h>

int main(int argc, const char *argv[]) {
//int main_9_6(int argc, const char *argv[]) {
    
    // 创建一个三行四列的二维数组
    int array[3][4];
    
    return 0;
}

/*
 1、思考：某公司，有3个销售小组，每组有4人。将本月的每个人的销售成绩保存起来。
 
    方法1:int array [12]。
    可以解决，但是不好定位，第2组第2个人
     
    方法2:声明3个长度为4数组。
    可以解决，但不好管理。
    int array1[4];
    int array2[4];
    int array3[4];
     
    方法3:用Excel。
    直观，方便定位数据。
 
 2、C语言中有像Excel那样有行有列的表格结构的数据？
    n 行 m 列？
    二维数组就是一个有行有列的表格。
 
 3、声明1个二维数组？
 1）、二维数组首先是一个数组，它符合数组的特点。
    元素的类型相同。
    存储数据的个数固定。
    方便管理数据。
 
 2）、二维数组独有的特点
    是1个有行有列的表格。
    使用单元格来存储数据。
    单元格就是二维数组的元素。
 
 3）、声明二维数组的语法
    元素类型 数组名[行数][列数];
 
    // 创建一个三行四列的二维数组（表格）
    int array[3][4];
    每1个单元格，是1个二维数组的1个元素。
    每个元素的类型是int。

 */

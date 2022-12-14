//  二维数组

#include <stdio.h>

//int  (int argc, const char *argv[]) {
int main_9_6(int argc, const char *argv[]) {
    
    {
        // 创建一个三行四列的二维数组
        
        int array[3][4];
        array[0][0] = 10;
        array[0][1] = 20;
        array[0][2] = 34;
        array[0][3] = 2;
        
        array[1][0] = 25;
        array[1][1] = 30;
        array[1][2] = 40;
        array[1][3] = 15;
        
        array[2][0] = 12;
        array[2][1] = 5;
        array[2][2] = 6;
        array[2][3] = 30;
        
        for(int i = 0;i<3;i++){
            for(int j = 0; j<4;j++){
                printf("%d ",array[i][j]);
            }
            printf("\n");
        }
    }
    // 7、使用二维数组时的注意点：
    {
        // 行数不能省略。
        // Error:Compile Error : Definition of variable with array type needs an explicit size or an initializer
        // int array[][4];
    }
    
    // 8、元素的初始化 - 全部初始化
    {
        // b、在声明的同时初始化每一个元素。
        int array[3][4]={
            {10,20,34,2}, // 第0行
            {25,30,40,15},// 第1行
            {12,5,6,30} // 第2行
            
        };
        
        for(int i = 0;i<3;i++){
            for(int j = 0; j<4;j++){
                printf("%d ",array[i][j]);
            }
            printf("\n");
        }
        
        // c、在声明的同时初始化每一个元素。省略行数。
        int array2[][4]={
            {10,20,34,2}, // 第0行
            {25,30,40,15},// 第1行
            {12,5,6,30} // 第2行
            
        };
        
        // d、直接省略里面的大括号，编译器根据行数和列数自动判断哪些属于哪1行。
        int array3[3][4] = {10, 20, 34, 2, 25, 30, 40, 15, 12, 5, 6, 30};
        
        // e、直接省略里面的大括号，省略行数。
        int array4[][4] = {10, 20, 34, 2, 25, 30, 40, 15, 12, 5, 6, 30};
    }
    
    // 8、元素的初始化 - 部分初始化
    {
        int array[3][4] = {{10},{20},{30}};
        int array2[3][4] = {[1]={25,30,40,15},[2]={12,5,6,30}};
        int array3[3][4] = {[0][1]=20, [1][3]=60};
    }
    
    // 9、二维数组的基本使用
    {
        int array[3][4]={
            {10,20,34,2}, // 第0行
            {25,30,40,15},// 第1行
            {12,5,6,30} // 第2行
            
        };
        int max = 0;
        int sum = 0;
        for(int i = 0;i<3;i++){
            for(int j = 0; j<4;j++){
                if(array[i][j]>max){
                    max = array[i][j];
                }
                sum +=array[i][j];
            }
        }
        printf("max=%d\n",max);// 40
        printf("sum=%d\n",sum);// 229
        
    }
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
 
    // 创建一个三行四列的二维数组,即表格
    int array[3][4];
    每1个单元格，是1个二维数组的1个元素。
    每个元素的类型是int。
 
 4、术语
    1）、元素：元素就是这个表格的每1个单元格。所以二维数组存储数据的是表格中每一个单元格。
    2）、下标：元素的下标，二维数组的元素的下标有2个（行和列）。
    3）、长度：一般认为是单元格的个数。行*列
 
 5、如何往二维数组中存数据？
    1）、数组名[行下标][列下标]=数据。
    2）、赋值时，和数组的类型一致，否则会做自动类型转换。
    3）、行标列标不要越界。否则可能造成程序崩溃。
 
 6、如何从二维数组中取出数据？
    1）、通过下标来取。数组名[行下标][列下标]
    2）、行标列标不要越界。
 
 7、二维数组使用时注意点：
 1）、行数和列数
    声明时，必须指定行数和列数。
    行数和列数，可以是变量、常量、宏、表达式。
    行数和列数，也可以是1或0.但是一般不会这么用，因为没有意义。
    行数和列数不能是小数，也不能是负数。
 2）、元素的默认值
    声明数组后，但没有为元素赋值，此时，元素有值，是垃圾值。
  
 8、元素的初始化
    1）、全部初始化。
     a、先声明，再使用下标初始化。
         int array[3][4];
         array[0][0] = 10;
         array[0][1] = 20;
         array[0][2] = 34;
         array[0][3] = 2;
         
         array[1][0] = 25;
         array[1][1] = 30;
         array[1][2] = 40;
         array[1][3] = 15;
         
         array[2][0] = 12;
         array[2][1] = 5;
         array[2][2] = 6;
         array[2][3] = 30;
 
     b、在声明的同时初始化每一个元素。
         int array[3][4]={
             {10,20,34,2}, // 第0行
             {25,30,40,15},// 第1行
             {12,5,6,30} // 第2行
             
         };
     c、在声明的同时初始化每一个元素。省略行数。
         int array2[][4]={
             {10,20,34,2}, // 第0行
             {25,30,40,15},// 第1行
             {12,5,6,30} // 第2行
             
         };
 
    d、直接省略里面的大括号。
       编译器根据行数和列数自动判断哪些属于哪1行。
        int array3[3][4] = {10, 20, 34, 2, 25, 30, 40, 15, 12, 5, 6, 30};
    
    e、直接省略里面的大括号，省略行数。
       编译器根据列数和数据的个数自动判断行数。
       int array4[][4] = {10, 20, 34, 2, 25, 30, 40, 15, 12, 5, 6, 30};
 
 
    => b、c最常用。不需要记住所有，只需要记住最常用的用法。
 
   2)、部分初始化
    a、int array[3][4] = {{10},{20},{30}};
       初始化指定行的数据，其他元素被自动初始化为0
       10, 0, 0, 0
       20, 0, 0, 0
       30, 0, 0, 0
 
    b、int array[3][4] = {10,20,30};
       按照顺序初始化每1个元素，其他元素被自动初始化为0
       10,20,30,0
       0, 0, 0, 0
       0, 0, 0, 0
 
    c、int array[][4] = {10,20,30，40，50};
       省略行数，自动根据后面的元素的个数来计算行
       10,20,30,40
       50, 0, 0, 0
 
    d、int array[3][4] = {[1]={25,30,40,15},[2]={12,5,6,30}};
       给指定的行初始化，其他的元素自动初始化为0
       0,  0,  0,  0
       25, 30, 40, 15
       12, 5,  6,  30
 
 
    e、int array[3][4] = {[0][1]=20, [1][3]=60};
       给指定的元素赋值，其他的元素自动初始化为0
       0,  20, 0,  0
       0,  0,  60, 0
       0,  0,  0,  0
    =>b 最常用。 不需要记住所有，只需要记住最常用的用法。
 
9、二维数组的基本使用。
   找max、
   求和、
   求平均值
 
 10、什么时候使用二维数组？
    特点：有行有列的表格。当需要存储类似表格的数据时。
    比如：2d 地图游戏 - 五子棋/走出迷宫/象棋。
 
 */


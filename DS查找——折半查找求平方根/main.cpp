//
//  main.cpp
//  DS查找——折半查找求平方根
//
//  Created by Jacky on 2021/5/12.
//

/*
题目描述

假定输入y是整数，我们用折半查找来找这个平方根。在从0到y之间必定有一个取值是y的平方根，如果我们查找的数x比y的平方根小，则x2<y，如果我们查找的数x比y的平方根大，则x2>y，我们可以据此缩小查找范围，当我们查找的数足够准确时（比如满足|x2-y|<0.00001），就可以认为找到了y的平方根。

比如求5的平方根x，则x一定满足   0<=x<=5，取x为(5+0)/2=2.5，因为2.5的平方为6.25>5，所以x一定小于2.5，也即x满足0<=x<=2.5，取x为1.25，以此类推

最后求得5的平方根为2.236
温馨提示： 计算过程中为确保精确性，计算变量的类型都用double
保留小数位数请采用printf("%.3lf\n",x) 的格式输出
程序框架参考平时练习中折半查找的方法

输入

第1行输入一个整数n(<100)，表示有n个数
从第2行起到第n+1行输入n个整数
输出

输出n个数的平方根，精确到小数点后三位。
样例输入

2
13
5
样例输出

3.606
2.236

*/

#define E 0.00001
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        double y;
        cin >> y;
        double low = 0, high = y, x = (low + high) / 2;
        while (fabs(x * x - y) > E) {
            if (x * x > y) {
                high = x;
            } else {
                low = x;
            }
            x = (low + high) / 2;
            
        }
        
        printf("%.3lf\n",x);
    }

    return 0;
}

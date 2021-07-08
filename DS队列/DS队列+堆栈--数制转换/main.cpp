//
//  main.cpp
//  DS队列+堆栈--数制转换
//
//  Created by Jacky on 2021/3/31.
//

/*
 问题 B: DS队列+堆栈--数制转换
 时间限制: 1 Sec  内存限制: 128 MB
 提交: 328  解决: 135
 [提交][状态][讨论版]
 题目描述
 对于任意十进制数转换为k进制，包括整数部分和小数部分转换。整数部分采用除k求余法，小数部分采用乘k取整法例如x=19.125，求2进制转换

 整数部分19，                    小数部分0.125
 19 / 2 = 9 … 1                    0.125 * 2 = 0.25 … 0
 9 / 2 = 4 … 1                    0.25 * 2 = 0.5   … 0
 4 / 2 = 2 … 0                     0.5 * 2 = 1     … 1
 2 / 2 = 1 … 0
 1 / 2 = 0 … 1
 所以整数部分转为 10011，小数部分转为0.001，合起来为10011.001

 提示整数部分可用堆栈，小数部分可用队列实现

 注意：必须按照上述方法来实现数制转换，其他方法0分

 输入
 第一行输入一个t，表示下面将有t组测试数据。

 接下来每行包含两个参数n和k，n表示要转换的数值，可能是非整数；k表示要转换的数制，1<k<=16

 输出
 对于每一组测试数据，每行输出转换后的结果，结果精度到小数点后3位

 输出小数点后几位的代码如下：

 #include <iostream>
 #include <iomanip>
 using namespace std;

 int main()
 {
   double r = 123.56789;
   cout<<fixed<<setprecision(4)<<r<<endl;   //输出小数点后4

  return 0;
 }

 样例输入
 2
 19.125 2
 15.125 16
 样例输出
 10011.001
 F.200
 提示
  例如：十进制数254.3879转换为6进制数。

 整数部分254，
 254 / 6 = 42 ... 2
 42 / 6 = 7 ... 0
 7 / 6 = 1 ... 1
 1 / 6 = 0 ... 1

 小数部分0.3879，
 0.3879 * 6 = 2.3274   ...  2
 0.3274 * 6 = 1.9644 ... 1
 0.9644 * 6 = 5.7864 ... 5
 所以整数部分转为 1102，小数部分转为0.215，转换后的6进制数合起来为1102.215
 */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int t, integer, k, remainder;
    double v, decimal;
    cin >> t;
    while (t--) {
        stack<int>integer_part;
        queue<int>decimal_part;
        cin >> v >> k;
        integer = (int)v;
        decimal = v - integer;
        // 处理整数部分
        while (integer) {
            remainder = integer % k;
            integer_part.push(remainder);
            integer /= k;
        }
        // 处理小数部分
        int pos = 0;
        if (decimal) {
            while (decimal<1 && pos < 3) {
                pos++;
                decimal *= k;
                decimal_part.push(decimal);
                decimal = decimal -(int)decimal;
            }
        }
        // 小数点保留到后三位
        while (decimal_part.size() < 3) {
            decimal_part.push(0);
        }
        
        // output
        if (!integer_part.empty()) {
            while (!integer_part.empty()) {
                int tmp = integer_part.top();
                if (tmp < 10) cout << tmp;
                else cout << char('A' + tmp - 10);
                integer_part.pop();
            }
        } else {
            cout << 0;
        }
        pos = 0;
        cout << '.';
        while (!decimal_part.empty() && pos < 3) {
            pos++;
            int tmp = decimal_part.front();
            if (tmp < 10) cout << tmp;
            else cout << char('A' + tmp - 10);
            decimal_part.pop();
        }
        cout << endl;
    }
    return 0;
}

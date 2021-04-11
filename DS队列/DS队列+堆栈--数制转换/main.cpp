//
//  main.cpp
//  DS队列+堆栈--数制转换
//
//  Created by Jacky on 2021/3/31.
//

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

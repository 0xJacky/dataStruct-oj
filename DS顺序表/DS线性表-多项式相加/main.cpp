//
//  main.cpp
//  DS线性表-多项式相加
//
//  Created by Jacky on 2021/3/18.
//

/*
 题目描述
 对于一元多项式 p(x)=p0+p1x+p2x2+ … +pnxn ，每个项都有系数和指数两部分，例如p2x2的系数为p2,指数为2。

 编程实现两个多项式的相加。

 例如5+x+2x2+3x3，-5-x+6x2+4x4，两者相加结果：8x2+3x3+4x4

 其中系数5和-5都是x的0次方的系数，相加后为0，所以不显示。x的1次方同理不显示。

 可用顺序表或单链表实现。

 输入
 第1行：输入t表示有t组测试数据

 第2行：输入n表示有第1组的第1个多项式包含n个项

 第3行：输入第一项的系数和指数，以此类推输入n行

 接着输入m表示第1组的第2个多项式包含m项

 同理输入第2个多项式的m个项的系数和指数

 参考上面输入第2组数据，以此类推输入t组

 假设所有数据都是整数

 输出
 对于每1组数据，先用两行输出两个原来的多项式，再用一行输出运算结果，不必考虑结果全为0的情况

 输出格式参考样本数据，格式要求包括：

 1.如果指数或系数是负数，用小括号括起来。

 2.如果系数为0，则该项不用输出。

 3.如果指数不为0，则用符号^表示，例如x的3次方，表示为x^3。

 4.多项式的每个项之间用符号+连接，每个+两边加1个空格隔开。

 样例输入
 2
 4
 5 0
 1 1
 2 2
 3 3
 4
 -5 0
 -1 1
 6 2
 4 4
 3
 -3 0
 -5 1
 2 2
 4
 9 -1
 2 0
 3 1
 -2 2
 样例输出
 5 + 1x^1 + 2x^2 + 3x^3
 (-5) + (-1)x^1 + 6x^2 + 4x^4
 8x^2 + 3x^3 + 4x^4
 (-3) + (-5)x^1 + 2x^2
 9x^(-1) + 2 + 3x^1 + (-2)x^2
 9x^(-1) + (-1) + (-2)x^1
 */

#define MAX 10000
#define BASE 5000
#include <iostream>
using namespace std;

class SeqList{
public:
    int * data;
    int * used;
    int used_i;
    SeqList() {
        data = new int[MAX];
        used = new int[MAX];
        used_i = 0;
        for (int i = 0; i < MAX; i++) {
            data[i] = 0;
        }
    }
    void insert(int coefficient, int exponent) {
        data[BASE+exponent] = coefficient;
        used[used_i++] = BASE+exponent;
    }
    void printFormatNum(int n) {
        if (n > 0) {
            cout << n;
        } else if (n < 0) {
            cout << "(" << n << ")";
        }
    }
    void printItem(int i) {
        if (data[used[i]]) {
            printFormatNum(data[used[i]]);
            if (used[i] - BASE != 0) {
                cout << "x^";
            }
            printFormatNum(used[i] - BASE);
        }
    }
    void display() {
        for (int i = 0; i < used_i - 1; i++) {
            printItem(i);
            cout << " + ";
        }
        if (used[used_i-1]) {
            printItem(used_i - 1);
        }
        cout << endl;
    }
};

SeqList sum(SeqList &sql1, SeqList &sql2) {
    SeqList sql;
    for (int i = 0; i < MAX; i++) {
        sql.data[i] = sql1.data[i] + sql2.data[i];
        if(sql.data[i] != 0) {
            sql.used[sql.used_i++] = i;
        }
    }
    return sql;
}

int main() {
    int n, m, c, e;
    cin >> n;
    while (n--) {
        SeqList sql1, sql2;
        cin >> m;
        while (m--) {
            cin >> c >> e;
            sql1.insert(c, e);
        }
        sql1.display();
        cin >> m;
        while (m--) {
            cin >> c >> e;
            sql2.insert(c, e);
        }
        sql2.display();
        sum(sql1, sql2).display();
    }
    return 0;
}

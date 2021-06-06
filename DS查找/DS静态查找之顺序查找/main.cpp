//
//  main.cpp
//  DS静态查找之顺序查找
//
//  Created by Jacky on 2021/5/12.
//

/*
 题目描述

 给出一个队列和要查找的数值，找出数值在队列中的位置，队列位置从1开始

 要求使用带哨兵的顺序查找算法

 输入

 第一行输入n，表示队列有n个数据
 第二行输入n个数据，都是正整数，用空格隔开
 第三行输入t，表示有t个要查找的数值
 第四行起，输入t个数值，输入t行

 输出

 每行输出一个要查找的数值在队列的位置，如果查找不成功，输出字符串error

 样例输入

 8
 33 66 22 88 11 27 44 55
 3
 22
 11
 99
 样例输出

 3
 5
 error

 */

#include <iostream>
using namespace std;

void findKey(int v, int d[], int length) {
    // 哨兵
    d[0] = v;
    int i;
    for (i = length; d[i] != v; i--);
    if (i) {
        cout << i << endl;
    } else {
        cout << "error" << endl;
    }
}

int main() {
    int n, t, *d, v;
    cin >> n;
    d = new int[n+10];
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    
    cin >> t;
    while (t--) {
        cin >> v;
        findKey(v, d, n);
    }
    
    delete [] d;
    
    return 0;
}

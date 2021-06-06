//
//  main.cpp
//  DS静态查找之顺序索引查找
//
//  Created by Jacky on 2021/5/12.
//

/*
 题目描述

 给出一个队列和要查找的数值，找出数值在队列中的位置，队列位置从1开始

 要求使用顺序索引查找算法，其中索引表查找和块内查找都采用不带哨兵、从头开始的顺序查找方法。

 输入

 第一行输入n，表示主表有n个数据
 第二行输入n个数据，都是正整数，用空格隔开
 第三行输入k，表示主表划分为k个块，k也是索引表的长度
 第四行输入k个数据，表示索引表中每个块的最大值
 第五行输入t，表示有t个要查找的数值
 第六行起，输入t个数值，输入t行

 输出

 每行输出一个要查找的数值在队列的位置和查找次数，数据之间用短划线隔开，如果查找不成功，输出字符串error

 样例输入

 18
 22 12 13 8 9 20 33 42 44 38 24 48 60 58 74 57 86 53
 3
 22 48 86
 6
 13
 5
 48
 40
 53
 90
 样例输出

 3-4
 error
 12-8
 error
 18-9
 error
 提示
 */

#include <iostream>
using namespace std;

bool findKey(int v, int *d, int length, int edge, int *times, int *pos) {
    int i;
    bool flag = false;
    for (i = 1; i <= length && i <= edge; i++) {
        (*times)++;
        if (*(d+i) == v) {
            *pos = i;
            flag = true;
            break;
        }
    }

    return flag;
}

int main() {
    int *mainTable, *indexTable, n, k, t, v;
    
    cin >> n;
    mainTable = new int[n+10];
    for (int i = 1; i <= n; i++) {
        cin >> mainTable[i];
    }
    
    cin >> k;
    indexTable = new int[k];
    for (int i = 0; i < k; i++) {
        cin >> indexTable[i];
    }
    
    cin >> t;
    while (t--) {
        cin >> v;
        // 每个块的长度
        int ans = 1, blockLength = n / k, pos, times;
        for (int i = 0; i < k; i++) {
            if (v <= indexTable[i]) {
                break;
            }
            ans++;
        }
        times = ans;
        if (findKey(v, mainTable + ((ans - 1) * blockLength), blockLength, n, &times, &pos)) {
            cout << (ans - 1) * blockLength + pos << '-' << times << endl;
        } else {
            cout << "error" << endl;
        }
        
        
        
    }
    
    return 0;
}

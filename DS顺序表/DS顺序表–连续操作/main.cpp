//
//  main.cpp
//  DS顺序表–连续操作
//
//  Created by Jacky on 2021/3/10.
//

/*
题目描述
建立顺序表的类，属性包括：数组、实际长度、最大长度（设定为1000）

该类具有以下成员函数：

构造函数：实现顺序表的初始化。

插入多个数据的multiinsert(int i, int n, int item[])函数，实现在第i个位置，连续插入来自数组item的n个数据，即从位置i开始插入多个数据。

删除多个数据的multidel(int i, int n)函数，实现从第i个位置开始，连续删除n个数据，即从位置i开始删除多个数据。

编写main函数测试该顺序表类。

输入
第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据

第2行先输入i表示插入开始的位置，再输入k表示有k个插入数据，接着输入k个数据

第3行先输入i表示删除开始的位置，再输入k表示要删除k个数据

输出
顺序表内容包括顺序表的实际长度和数据，数据之间用空格隔开

第1行输出创建后的顺序表内容

第2行输出执行连续插入后的顺序表内容

第3行输出执行连续删除后的顺序表内容

样例输入
6 11 22 33 44 55 66
2 3 99 88 77
4 5

样例输出
6 11 22 33 44 55 66
9 11 99 88 77 22 33 44 55 66
4 11 99 88 66
*/

#include <iostream>
using namespace std;

#define ok 0
#define error -1

class SeqList {
private:
    int *list;
    int maxsize;
    int size;

public:
    // 构造函数，对象初始化设定
    SeqList() {
        maxsize = 1000;
        size = 0;
        list = new int[maxsize];
    }

    // 析构函数
    ~SeqList() {
        delete[] list;
    }
    
    int list_insert(int i, int item) {
        if (i < 1 || i > size + 1) {
            return error;
        }
        size++;
        for (int k = size - 1; k >= i - 1; k--) {
            list[k + 1] = list[k];
        }
        list[i - 1] = item;
        return ok;
    }

    //实现在第i个位置，连续插入来自数组item的n个数据，即从位置i开始插入多个数据。
    int multiinsert(int i, int n, int item[]) {
        if (i < 1 || i > size + 1) {
            return error;
        }
        size += n;
        for (int k = size - 1; k >= i - 1; k--) {
            list[k + n] = list[k];
        }
        for (int k = 0; k < n; k++) {
            list[i+k-1] = item[k];
        }
        return ok;
    }

    // 实现从第i个位置开始，连续删除n个数据，即从位置i开始删除多个数据。
    int multidel(int i, int n) {
        if (i < 1 || i > size) {
            return error;
        }
        for (int k = i - 1; k < size; k++) {
            list[k] = list[k + n];
        }
        size -= n;
        return ok;
    }

    void list_display() {
        cout << size << " ";
        for (int i = 0; i < size; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, *p, place, v;
    cin >> n;
    SeqList sql;
    // 1
    for (int i = 1; i <= n; i++) {
        cin >> v;
        sql.list_insert(i, v);
    }
    sql.list_display();
    
    // 2
    cin >> place >> n;
    p = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sql.multiinsert(place, n, p);
    sql.list_display();
    delete[] p;
    
    //3
    cin >> place >> n;
    sql.multidel(place, n);
    sql.list_display();
    
    return 0;
}

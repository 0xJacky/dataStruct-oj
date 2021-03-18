//
//  main.cpp
//  DS顺序表--合并操作
//
//  Created by Jacky on 2021/3/10.
//

/*
 题目描述
 
 建立顺序表的类，属性包括：数组、实际长度、最大长度（设定为1000）

 已知两个递增序列，把两个序列的数据合并到顺序表中，并使得顺序表的数据递增有序

 输入
 
 第1行先输入n表示有n个数据，接着输入n个数据，表示第1个序列，要求数据递增互不等

 第2行先输入m表示有m个数据，接着输入m个数据，表示第2个序列，要求数据递增互不等

 输出
 
 顺序表内容包括顺序表的实际长度和数据，数据之间用空格隔开

 第1行输出创建后的顺序表内容

 样例输入
 3 11 33 55
 5 22 44 66 88 99
 
 样例输出
 8 11 22 33 44 55 66 88 99
 
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
    
    SeqList(SeqList & sql1, SeqList & sql2) {
        maxsize = 1000;
        size = 0;
        list = new int[maxsize];
        if (sql1.size == 0) {
            multiinsert(1, sql2.size, sql2.list);
        }
        if (sql2.size == 0) {
            multiinsert(1, sql1.size, sql1.list);
        }
        int i = 0, j = 0;
        while (true) {
            if (sql1.list[i] < sql2.list[j]) {
                list_insert(size + 1, sql1.list[i]);
                if (i < sql1.size - 1) {
                    i++;
                } else {
                    multiinsert(size + 1, sql2.size - j, sql2.list, j);
                    break;
                }
            } else {
                list_insert(size + 1, sql2.list[j]);
                if (j < sql2.size - 1) {
                    j++;
                } else {
                    multiinsert(size + 1, sql1.size - i, sql1.list, i);
                    break;
                }
            }
        }
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
    int multiinsert(int i, int n, int item[], int start = 0) {
        if (i < 1 || i > size + 1) {
            return error;
        }
        size += n;
        for (int k = size - 1; k >= i - 1; k--) {
            list[k + n] = list[k+start];
        }
        for (int k = 0; k < n; k++) {
            list[i+k-1] = item[k+start];
        }
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
    int n, v;
    SeqList sql1, sql2;
    cin >> n;
    // 1
    for (int i = 1; i <= n; i++) {
        cin >> v;
        sql1.list_insert(i, v);
    }
    // 2
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        sql2.list_insert(i, v);
    }
    
    SeqList sql3(sql1, sql2);
    sql3.list_display();
    
    return 0;
}

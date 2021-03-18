//
//  main.cpp
//  DS顺序表之循环移位
//
//  Created by Jacky on 2021/3/10.
//

/*
题目描述
顺序表的移位是循环移位，例如顺序表：1，2，3，4，5，6。如果左移1位，即原来的头元素移动到末尾，其它元素向左移1位，变成2，3，4，5，6，1。同理，如果右移1位，即原来的尾元素移动到头，其它元素向右移1位，变成6，1，2，3，4，5。以下是移位的多个例子：

原数据：1，2，3，4，5，6

左移3位：4，5，6，1，2，3，与原数据对比

右移4位：3，4，5，6，1，2，与原数据对比

请编写程序实现顺序表的循环移位操作

输入
第1行输入n表示顺序表包含的·n个数据

第2行输入n个数据，数据是小于100的正整数

第3行输入移动方向和移动的位数，左移方向为0，右移方向为1

第4行输入移动方向和移动的位数，左移方向为0，右移方向为1

注意：移动操作是针对上一次移动后的结果进行的

输出
第一行输出创建后，顺序表内的所有数据，数据之间用空格隔开

第二行输出第一次移位操作后，顺序表内的所有数据，数据之间用空格隔开

第三行输出第二次移位操作后，顺序表内的所有数据，数据之间用空格隔开

样例输入
5
11 22 33 44 55
0 2
1 4

样例输出
11 22 33 44 55
33 44 55 11 22
44 55 11 22 33
*/

#include <iostream>
using namespace std;

#define ok 0
#define error -1

int abs(int n) {
    return n > 0 ? n : -n;
}

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

    // 左0右1
    void shift_list(int direction, int step) {
        int *tmp = new int[maxsize];
        int cursor = 0;
        if (direction) {
            // 右移
            for (int i = size - step; i < size; i++) {
                tmp[cursor++] = list[i];
            }
            
            for (int i = 0; i < size - step; i++) {
                tmp[cursor++] = list[i];
            }
            
        } else {
            // 左移
            for (int i = step; i < size; i++) {
                tmp[cursor++] = list[i];
            }
            
            for (int i = 0; i < step; i++) {
                tmp[cursor++] = list[i];
            }
        }
        delete [] list;
        list = tmp;
    }
    
  void list_display() {
        for (int i = 0; i < size; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, dir, v;
    SeqList sql;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        sql.list_insert(i, v);
    }
    sql.list_display();
    
    for (int i = 0; i < 2; i++) {
        cin >> dir >> n;
        sql.shift_list(dir, n);
        sql.list_display();
    }
    
    return 0;
}

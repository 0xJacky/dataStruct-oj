//
//  main.cpp
//  DS哈希查找--链地址法
//
//  Created by Jacky on 2021/5/25.
//

/*
 题目描述
  给出一个数据序列，建立哈希表，采用求余法作为哈希函数，模数为11，哈希冲突用链地址法和表头插入
 如果首次查找失败，就把数据插入到相应的位置中
 实现哈希查找功能
 输入
 第一行输入n，表示有n个数据
 第二行输入n个数据，都是自然数且互不相同，数据之间用空格隔开
 第三行输入t，表示要查找t个数据
 从第四行起，每行输入一个要查找的数据，都是正整数
 输出
 每行输出对应数据的查找结果
 样例输入
 6
 11 23 39 48 75 62
 6
 39
 52
 52
 63
 63
 52
 样例输出
 6 1
 error
 8 1
 error
 8 1
 8 2
 提示
 注意，当两次输入要相同的查找数据，如果第一次查找不成功就会执行插入，那么第二次查找必然成功，且查找次数为1次（因为做表头插入）

 例如示例数据中输入两次52，第一次查找失败就把52插入到位置8，第二次查找就成功了，所以第一次输出error，第二次就输出8 1

 为什么第三次输入52会输出8 2

 */

#include <iostream>
#include <list>
#include <map>
#define N 11
using namespace std;

class HashTable {
    map<int, list<int>> table;
public:
    void store(int n) {
        table[n%N].push_front(n);
    }
    void search(int n) {
        int count = 0;
        bool flag = false;
        for (auto it = table[n%N].begin(); it != table[n%N].end(); ++it) {
            ++count;            
            if (*it == n) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << n%N << ' ' << count << endl;
        } else {
            table[n%N].push_front(n);
            cout << "error" << endl;
        }
    }
};

int main() {
    int n, t;
    while(cin >> n) {
        HashTable table;
        while (n--) {
            cin >> t;
            table.store(t);
        }
        
        cin >> n;
        cout << "++++++++++++" << endl;
        cout << "------------" << endl;
        while (n--) {
            cin >> t;
            table.search(t);
        }
        
    }
    return 0;
}

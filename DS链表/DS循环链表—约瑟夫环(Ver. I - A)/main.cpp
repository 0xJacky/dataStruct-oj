//
//  main.cpp
//  DS循环链表—约瑟夫环(Ver. I - A)
//
//  Created by Jacky on 2021/3/24.
//

/*
 题目描述
 N个人坐成一个圆环（编号为1 - N），从第S个人开始报数，数到K的人出列，后面的人重新从1开始报数。问最后剩下的人的编号。
 例如：N = 3，K = 2，S = 1。2号先出列，然后是1号，最后剩下的是3号。
 要求使用循环链表实现。
 输入
 测试数据有多组

 每组包括3个数N、K、S，表示有N个人，从第S个人开始，数到K出列。(1 <= N <= 10^6，1 <= K <= 10,  1 <= S <= N)

 输出
 出列的人的编号

 样例输入
 13 3 1
 3 2 1
 样例输出
 3 6 9 12 2 7 11 4 10 5 1 8 13
 2 1 3 
 */

#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode *next;
    int no;
    ListNode() {
        next = NULL;
    }
};

class LinkList {
public:
    ListNode *head;
    ListNode *last;
    int len;
    LinkList() {
        len = 0;
        head = new ListNode();
        last = head;
    }
    ~LinkList() {
        ListNode *p, *q;
        p = head;
        while (p != head) {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
        last = NULL;
    }
    // 尾部插入
    void push(int n) {
        last->next = new ListNode();
        last->next->no = n;
        last = last->next;
        // 循环链表
        last->next = head;
        len++;
    }
};

int main() {
    int n, k, s;
    while (scanf("%d %d %d", &n, &k, &s) != EOF) {
        LinkList list;
        for (int i = 1; i <= n; i++) {
            list.push(i);
        }
        
        auto p = list.head;

        // 从 s 个人开始
        for (int i = 0; i < s - 1; i++) {
            p = p->next;
        }
        
        while (list.len) {
            if (p->next == list.head) p = p->next;
            // 数到 k 的前驱节点
            for (int i = 0; i < k - 1; i++) {
                p = p->next;
                if (p->next == list.head) p = p->next;
            }
            // 待删除的节点
            auto pk = p->next;
            list.len--;
            cout << pk->no << " ";
            p->next = pk->next;
            delete pk;
        }
        cout << endl;
    }
    
    return 0;
}

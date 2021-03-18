//
//  main.cpp
//  DS单链表--结点交换
//
//  Created by Jacky on 2021/3/16.
//

/*
 题目描述
 用C++实现含头结点的单链表，然后实现单链表的两个结点交换位置。

 注意不能简单交换两个结点包含数据，必须通过修改指针来实现两个结点的位置交换

 交换函数定义可以参考：

 swap（int pa, int pb) //pa和pb表示两个结点在单链表的位置序号

 swap (ListNode * p, ListNode * q) //p和q表示指向两个结点的指针

 输入
 第1行先输入n表示有n个数据，接着输入n个数据

 第2行输入要交换的两个结点位置

 第3行输入要交换的两个结点位置

 输出
 第一行输出单链表创建后的所有数据，数据之间用空格隔开

 第二行输出执行第1次交换操作后的单链表数据，数据之间用空格隔开

 第三行输出执行第2次交换操作后的单链表数据，数据之间用空格隔开

 如果发现输入位置不合法，输出字符串error，不必输出单链表

 样例输入
 5 11 22 33 44 55
 1 4
 2 6

 样例输出
 11 22 33 44 55
 44 22 33 11 55
 error
 */

#include <iostream>
#define ok 0
#define error -1
using namespace std;

// 链表结点定义
class ListNode {
public:
    int data;
    ListNode *next;
    ListNode() {
        next = NULL;
    }
};

// 带头结点的单链表定义
class LinkList {
public:
    ListNode *head;
    int len;
    LinkList() {
        head = new ListNode();
        len = 0;
    }
    ~LinkList() {
        ListNode *p, *q;
        p = head;
        while (p != NULL) {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }

    // 把数值 item 插入第 i 个位置
    int LL_insert(int i, int item) {
        auto p = head;
        if (i < 1 || i > len + 1) {
            return error;
        }
        int j = 1;
        while (p && j < i) {
            j++;
            p = p->next;
        }
        if (!p) {
            return error;
        }
        auto s = new ListNode();
        s->data = item;
        s->next = p->next;
        p->next = s;
        len++;
        return ok;
    }

    // 返回第i-1个结点的指针，如果不存在返回 NULL
    ListNode *LL_index_prev(int i) {
        auto p = head;
        int j = 1;
        // 获取 i-1 结点
        while (p && j < i) {
            j++;
            p = p->next;
        }
        return p;
    }

    // 输出单链表的内容
    void LL_display() {
        ListNode *p;
        p = head->next;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 交换
    int swap(int p1, int p2) {
        auto n1_prev = LL_index_prev(p1);
        auto n2_prev = LL_index_prev(p2);
        if (!(n1_prev && n1_prev->next && n2_prev && n2_prev->next)) {
            return error;
        }
        auto n1 = n1_prev->next;
        auto n2 = n2_prev->next;
        auto n1_next = n1->next;
        auto n2_next = n2->next;

        n1->next = n2_next;
        n2->next = n1_next;

        n1_prev->next = n2;
        n2_prev->next = n1;
        
        return ok;
    }
};

int main() {
    int n, p1, p2, item;
    LinkList list;

    // 1
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> item;
        list.LL_insert(i, item);
    }
    
    list.LL_display();

    for (int i = 0; i < 2; i++) {
        cin >> p1 >> p2;
        auto err = list.swap(p1, p2);
        if (err == error) {
            cout << "error" << endl;
        } else {
            list.LL_display();
        }
    }

    return 0;
}

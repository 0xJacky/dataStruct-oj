//
//  main.cpp
//  DS单链表--合并
//
//  Created by Jacky on 2021/3/16.
//

/*
 题目描述
 假定两个单链表是递增有序，定义并实现以下函数，完成两个单链表的合并，继续保持递增有序

 int LL_merge(ListNode *La, ListNode *Lb)

 输入
 第1行先输入n表示有n个数据，接着输入n个数据
  
 第2行先输入m表示有M个数据，接着输入m个数据

 输出
 输出合并后的单链表数据，数据之间用空格隔开

 样例输入
 3 11 33 55 4 22 44 66 88
 样例输出
 11 22 33 44 55 66 88
 
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
    LinkList(bool input = true) {
        head = new ListNode();
        len = 0;
        if (input) {
            int n, item;
            cin >> n;
            for (int i = 1; i <= n; i++) {
                cin >> item;
                LL_insert(i, item);
            }
        }
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
    // 返回第i个结点的指针，如果不存在返回 NULL
    ListNode *LL_index(int i) {
        auto p = head;
        int j = 1;
        // 获取 i-1 结点
        while (p && j < i) {
            j++;
            p = p->next;
        }
        // 获取 i 结点
        return p;
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

    // 批量插入 node 及其后的所有节点
    int multiInsert(int i, ListNode *node) {
        auto p = node;
        auto localNode = LL_index(i);

        while (p && localNode) {
            auto s = new ListNode();
            s->data = p->data;
            localNode->next = s;
            len++;
            localNode = localNode->next;
            p = p->next;
        }

        return ok;
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
};

int LL_merge(ListNode *La, ListNode *Lb) {
    LinkList list(false);
    auto p = La;
    auto q = Lb;
    while (p && q) {
        if (p->data < q->data) {
            list.LL_insert(list.len + 1, p->data);
            if (p->next != NULL) {
                p = p->next;
            } else {
                list.multiInsert(list.len + 1, q);
                break;
            }
        } else {
            list.LL_insert(list.len + 1, q->data);
            if (q->next != NULL) {
                q = q->next;
            } else {
                list.multiInsert(list.len + 1, p);
                break;
            }
        }
    }

    list.LL_display();

    return ok;
}

int main() {
    LinkList La, Lb;
    LL_merge(La.head->next, Lb.head->next);
    return 0;
}

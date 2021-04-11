//
//  main.cpp
//  DS单链表—删除重复元素
//
//  Created by Jacky on 2021/3/24.
//

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
        while (p != NULL) {
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
        len++;
    }
    
    // 删除节点
    void remove(ListNode *p) {
        if (p->next) {
            auto tmp = p->next;
            p->no = tmp->no;
            p->next = tmp->next;
            delete tmp;
        } else {
            auto q = head;
            while (q->next != p) {
                q = q->next;
            }
            delete p;
            q->next = NULL;
        }
        len--;
    }
    
    void display() {
        ListNode *p;
        p = head->next;
        cout << len << ": ";
        while (p != NULL) {
            cout << p->no << " ";
            p = p->next;
        }
        cout << endl;
    }
};



int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        LinkList list;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;
            list.push(k);
        }
        
        auto p = list.head->next;
        while (p) {
            auto q = list.head->next;
            while (q) {
                if (p != q) {
                    if (p->no == q->no) {
                        list.remove(q);
                    }
                }
                q = q->next;
            }
            p = p->next;
        }
        list.display();
    }
    return 0;
}

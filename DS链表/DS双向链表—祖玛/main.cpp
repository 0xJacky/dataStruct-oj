//
//  main.cpp
//  DS双向链表—祖玛时间
//
//  Created by Jacky on 2021/4/7.
//

#include <iostream>
#define ok 0
#define error -1
using namespace std;

class ListNode {
public:
    char data;
    ListNode *prev;
    ListNode *next;
    ListNode(): prev(this), next(this) {}
};

class DLinkList {
public:
    ListNode *head;
    int len;
    DLinkList() {
        head = new ListNode();
        len = 0;
    }
    ~DLinkList() {
        ListNode *p, *q;
        p = head;
        while (p != head) {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }
    
    int add(int i, char item) {
        auto p = head->next;
        if (i < 1 || i > len + 1) {
            return error;
        }
        int j = 1;
        while (p != head && j < i) {
            j++;
            p = p->next;
        }
        if (!p) {
            return error;
        }
        auto s = new ListNode();
        s->data = item;
        
        s->prev = p->prev;
        p->prev->next = s;
        s->next = p;
        p->prev = s;
    
        len++;
        return ok;
    }
    
    void remove(ListNode *p) {
        len--;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
    
    void display() {
        if (len) {
            auto p = head->next;
            while (p != head) {
                cout << p->data;
                p = p->next;
            }
        } else {
            cout << "-";
        }
        cout << endl;
    }
    
    void zuMa() {
        auto p = head->next;
        bool flag = true;
        while (flag) {
            p = head->next;
            flag = false;
            while (p != head) {
                auto q = p->next;
                int num = 0;
                while (q != head) {
                    if (p->data == q->data) {
                        num++;
                    }
                    if (num >= 2) {
                        flag = true;
                    }
                    
                    if (q->prev->data != q->data) {
                        break;
                    }
                    q = q->next;
                }
                if (flag) {
                    while (p != q) {
                        auto next = p->next;
                        remove(p);
                        p = next;
                    }
                    break;
                } else {
                    p = p->next;
                }
            }
        }
    }
    
};

int main() {
    int n, place;
    char item;
    string s;
    DLinkList list;
    cin >> s;
    auto len = s.length();
    for (int i = 0; i < len; i++) {
        list.add(i + 1, s[i]);
    }
    cin >> n;
    while (n--) {
        cin >> place >> item;
        list.add(place + 1, item);
        list.zuMa();
        list.display();
    }
    
    return 0;
}

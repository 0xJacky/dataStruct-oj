//
//  main.cpp
//  DS单链表--类实现
//
//  Created by Jacky on 2021/3/16.
//

/*
 题目描述
 用C++语言和类实现单链表，含头结点

 属性包括：data数据域、next指针域

 操作包括：插入、删除、查找

 注意：单链表不是数组，所以位置从1开始对应首结点，头结点不放数据

 类定义参考
 ```
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
     // 返回第i个结点的指针，如果不存在返回 NULL
     ListNode * LL_index(int i) {
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
     // 获取第 i 个元素的数据
     int LL_get(int i) {
         if (i < 1 || i > len) {
             return error;
         }
         auto p = head;
         int j = 1;
         while (p && j < i) {
             j++;
             p = p->next;
         }
         if (p->next == NULL) {
             return error;
         }
         return p->next->data;
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
     // 删除第 i 个结点
     int LL_del(int i) {
         if (i < 1 || i > len) {
             return error;
         }
         auto p = head;
         int j = 1;
         while (p && j < i) {
             j++;
             p = p->next;
         }
         if (p->next == NULL) {
             return error;
         }
         auto s = p->next;
         p->next = p->next->next;
         delete s;
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

 ```

 输入
 n第1行先输入n表示有n个数据，接着输入n个数据
 第2行输入要插入的位置和新数据
 第3行输入要插入的位置和新数据
 第4行输入要删除的位置
 第5行输入要删除的位置
 第6行输入要查找的位置
 第7行输入要查找的位置
 
 输出
 n
 数据之间用空格隔开，

 第1行输出创建后的单链表的数据

 每成功执行一次操作（插入或删除），输出执行后的单链表数据

 每成功执行一次查找，输出查找到的数据

 如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出单链表

 样例输入
 6 11 22 33 44 55 66
 3 777
 1 888
 1
 11
 0
 5
 样例输出
 11 22 33 44 55 66
 11 22 777 33 44 55 66
 888 11 22 777 33 44 55 66
 11 22 777 33 44 55 66
 error
 error
 44
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
    // 获取第 i 个元素的数据
    int LL_get(int i) {
        if (i < 1 || i > len) {
            return error;
        }
        auto p = head;
        int j = 1;
        while (p && j < i) {
            j++;
            p = p->next;
        }
        if (p->next == NULL) {
            return error;
        }
        return p->next->data;
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
    // 删除第 i 个结点
    int LL_del(int i) {
        if (i < 1 || i > len) {
            return error;
        }
        auto p = head;
        int j = 1;
        while (p && j < i) {
            j++;
            p = p->next;
        }
        if (p->next == NULL) {
            return error;
        }
        auto s = p->next;
        p->next = p->next->next;
        delete s;
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

int main() {
    int n, place, item;
    LinkList list;

    // 1
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> item;
        list.LL_insert(i, item);
    }
    list.LL_display();

    // 2, 3
    for (int i = 0; i < 2; i++) {
        cin >> place >> item;
        auto err = list.LL_insert(place, item);
        if (err == error) {
            cout << "error" << endl;
        } else {
            list.LL_display();
        }
    }

    // 4,5
    for (int i = 0; i < 2; i++) {
        cin >> place;
        auto err = list.LL_del(place);
        if (err == error) {
            cout << "error" << endl;
        } else {
            list.LL_display();
        }
    }

    // 6, 7
    for (int i = 0; i < 2; i++) {
        cin >> place;
        auto r = list.LL_get(place);
        if (r == error) {
            cout << "error" << endl;
        } else {
            cout << r << endl;
        }
    }

    return 0;
}

//
//  main.cpp
//  DS链表—学生宿舍管理时间限制
//
//  Created by Jacky on 2021/3/16.
//

/*
 题目描述

 假设某校有20间宿舍，宿舍编号101，102，...,120。
 每间只住一名学生。初始部分宿舍已用。
 用两个链表（已用宿舍链表和可用宿舍链表）维护宿舍的管理，实现宿舍分配、宿舍交回。

 约定已用宿舍链表按宿舍号升序链接。初始可用宿舍链表也按宿舍号升序链接。

 宿舍分配从可用宿舍链表中摘取第一间宿舍分配给学生。学生交回的宿舍挂在可用宿舍链表最后。

 备注：使用单链表或静态链表。不用考虑宿舍分配和交回不成功的情况。


 输入

 初始宿舍状态，第一行输入n，表示已用宿舍n间

 后跟n行数据，每行格式为：宿舍号 学生姓名

 操作次数m，后跟m行操作，操作格式如下：

 assign 学生 //为学生分配宿舍，从可用宿舍链表头摘取一间宿舍，

 ​          //按宿舍号升序挂在已用宿舍链表中。

 return 宿舍号  //学生退宿舍，删除已用宿舍链表中对应结点，

 ​             //挂在可用宿舍链表尾部。

 display_free  //输出可用宿舍链表信息。

 display_used  //输出已用宿舍链表信息。


 输出

  display_free依次输出当前可用宿舍链表中的宿舍号，具体格式见样例。

  display_used依次输出当前已用宿舍链表中的学生和宿舍号，具体格式见样例。

 样例输入
 5
 李明  103
 张三  106
 王五  107
 钱伟  112
 章立  118
 8
 assign 李四
 assign 赵六
 return 118
 return 101
 assign 马山
 display_used
 assign 林立
 display_free

 ## 样例输出
 赵六(102)-李明(103)-马山(104)-张三(106)-王五(107)-钱伟(112)
 108-109-110-111-113-114-115-116-117-119-120-118-101

 */

#define NUM 20
#define FIRSTNO 101
#include <iostream>
#define ok 0
#define error -1
using namespace std;

// 链表结点定义
class ListNode {
public:
    int no;
    string user;
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
        auto p = head->next;
        int j = 1;
        while (p && j < i) {
            j++;
            p = p->next;
        }
        return p;
    }
    
    // 把 user 插入第 i 个位置
    int LL_insert(int i, int no, string user) {
        auto p = head;
        auto s = new ListNode();
        int j = 1;
        while (p && j < i) {
            j++;
            p = p->next;
        }
        if (!p) {
            return error;
        }
        s->next = p->next;
        s->no = no;
        s->user = user;
        p->next = s;
        len++;
        return ok;
    }
    
    // 删除按 user 节点
    ListNode * LL_del(string user) {
        auto p = head;
        while (p) {
            if (p->next->user == user) {
                break;
            }
            p = p->next;
        }
        auto s = p;
        p->next = p->next->next;
        return s;
    }
    
    // 删除按 no 节点
    ListNode * LL_del(int no) {
        auto p = head;
        while (p) {
            if (p->next->no == no) {
                break;
            }
            p = p->next;
        }
        auto s = p;
        p->next = p->next->next;
        return s;
    }
    
    // 删除按 no 节点
    ListNode * LL_delI(int i) {
        auto p = head;
        int j = 1;
        while (p && j < i - 1) {
            j++;
            p = p->next;
        }
        auto s = p;
        p->next = p->next->next;
        return s;
    }
    
    // 输出单链表的内容
    void LL_display(bool showAll = false) {
        ListNode *p;
        p = head->next;
        while (p) {
            if (showAll) {
                cout << p->user << "(" << p->no << ")";
            } else {
                cout << p->no;
            }
            if (p->next != NULL) {
                cout << "-";
            }
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    LinkList free, used;
    int n, no;
    string func, user;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> user >> no;
        used.LL_insert(i, no, user);
    }
    // used.LL_display(true);
    auto p = used.LL_index(1);
    no = FIRSTNO;
    int j = 1;
    while (p) {
        if (no < p->no) {
            free.LL_insert(j++, no++, "");
        } else {
            no++;
            p = p->next;
        }
    }
    // free.LL_display();
    cin >> n;
    while (n--) {
        cin >> func;
        if (func == "assign") {
            cin >> user;
            // 为学生分配宿舍，从可用宿舍链表头摘取一间宿舍
            auto n = free.LL_delI(1);
            // 挂在已用宿舍的链表
            int j = 1;
            for (auto p = used.head; p->next!= NULL;p = p->next) {
                if (n->no < p->no) {
                    used.LL_insert(j, n->no, n->user);
                }
                j++;
            }
            delete n;
        } else if (func == "return") {
            cin >> no;
            // 删除对应节点
            auto n = used.LL_del(no);
            // 挂在可用宿舍链表尾部
            free.LL_insert(free.len+1, n->no, n->user);
            delete n;
        } else if (func == "display_free") {
            free.LL_display();
        } else if (func == "display_used") {
            used.LL_display();
        }
    }
    return 0;
}

//
//  main.cpp
//  DS二叉树--后序遍历非递归算法
//
//  Created by Jacky on 2021/5/10.
//

/*
 题目描述
 求一颗树的后序遍历的非递归算法
 要求：必须是非递归算法，使用堆栈对象来实现
 建树方法采用“先序遍历+空树用0表示”的方法
 算法流程：
  
 输入
 第一行输入一个整数t，表示有t个测试数据
 第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行
 输出
 逐行输出每个二叉树的后序遍历结果
 样例输入
 3
 AB0C00D00
 ABC00D00EF000
 ABCD0000E0F00
 样例输出
 CBDA
 CDBFEA
 DCBFEA
 提示
*/

#include <iostream>
#include <stack>
using namespace std;

class BiTreeNode {
public:
    BiTreeNode * LeftChild;
    BiTreeNode * RightChild;
    char data;
    int tag;
    BiTreeNode(): LeftChild(NULL), RightChild(NULL), data('\0') {}
    BiTreeNode(int t): LeftChild(NULL), RightChild(NULL), tag(t) {}
};

class BiTree {
    string strTree;
    int pos;
    BiTreeNode * Root;
    BiTreeNode * CreateTree() {
        BiTreeNode *T;
        char ch;
        ch = strTree[pos++];
        if (ch == '0')
            T = NULL;
        else {
            T = new BiTreeNode();
            T->data = ch;                    //生成根结点
            T->LeftChild = CreateTree();   //构造左子树
            T->RightChild = CreateTree();  //构造右子树
        }
        return T;
    }
public:
    void PostOrder() {
        stack<BiTreeNode *>s1;
        stack<BiTreeNode *>s2;
        auto T = Root;
        if(!T) return;
        auto p = T;
        do {
            if (p) {
                // 若 p 不空，p进栈s1，tag赋值0进栈s2
                s1.push(p);
                auto tag = new BiTreeNode(0);
                s2.push(tag);
                // p = p->Lchild, 跳转1
                p = p->LeftChild;
                continue;
            }
            if (s1.empty()) {
                break;
            }
            if (!p) {
                auto tag = s2.top();
                if (tag->tag == 0) {
                    tag->tag = 1;
                    p = s1.top()->RightChild;
                } else {
                    p = s1.top();
                    s1.pop();
                    s2.pop();
                    cout << p->data;
                    p = NULL;
                }
            }
        } while (!s1.empty());
    }
    void CreateTree(string strTree) {
        this->strTree = strTree;
        pos = 0;
        Root = CreateTree();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        BiTree bi;
        bi.CreateTree(s);
        bi.PostOrder();
        cout << endl;
    }
    return 0;
}

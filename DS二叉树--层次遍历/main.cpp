//
//  main.cpp
//  DS二叉树--层次遍历
//
//  Created by Jacky on 2021/5/10.
//

/*
 题目描述
 层次遍历二叉树，是从根结点开始遍历，按层次次序“自上而下，从左至右”访问树中的各结点。
 建树方法采用“先序遍历+空树用0表示”的方法
 要求：采用队列对象实现，函数框架如下：
  
 输入
 第一行输入一个整数t，表示有t个测试数据
 第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行
 输出
 逐行输出每个二叉树的层次遍历结果
 样例输入
 2
 AB0C00D00
 ABCD00E000FG00H0I00
 样例输出
 ABDC
 ABFCGHDEI
 提示
 */

#include <iostream>
#include <queue>
using namespace std;

class BiTreeNode {
public:
    BiTreeNode * LeftChild;
    BiTreeNode * RightChild;
    char data;
    BiTreeNode(): LeftChild(NULL), RightChild(NULL), data('\0') {}
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
    
    void LevelOrder(BiTreeNode * t) {
        queue<BiTreeNode *>tq;
        BiTreeNode *p = t;
        // 设 p 是指向当前节点的指针变量，如果 p 不空，p 入队，然后执行以下循环
        if (p) {
            tq.push(p);
            // 当队列不空
            while (!tq.empty()) {
                // 把队首元素出队到p，注意这里代码不止1行
                p = tq.front();
                tq.pop();
                // 输出 p 的数据，表示p已遍历
                if (p) {
                    cout << p->data;
                    // 把 p 的左右节点以此入队
                    tq.push(p->LeftChild);
                    tq.push(p->RightChild);
                }
            }
        }
    }
public:
    void LevelOrder() {
        LevelOrder(Root);
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
        bi.LevelOrder();
        cout << endl;
    }
    
    return 0;
}

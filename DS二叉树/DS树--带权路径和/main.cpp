//
//  main.cpp
//  DS树--带权路径和
//
//  Created by Jacky on 2021/4/27.
//

/*
 题目描述
 计算一棵二叉树的带权路径总和，即求赫夫曼树的带权路径和。

 已知一棵二叉树的叶子权值，该二叉树的带权案路径和APL等于叶子权值乘于根节点到叶子的分支数，然后求总和。如下图中，叶子都用大写字母表示，权值对应为：A-7，B-6，C-2，D-3

 树的带权路径和 = 7*1 + 6*2 + 2*3 + 3*3 = 34



 本题二叉树的创建参考前面的方法

 输入
 第一行输入一个整数t，表示有t个二叉树

 第二行输入一棵二叉树的先序遍历结果，空树用字符‘0’表示，注意输入全是英文字母和0，其中大写字母表示叶子

 第三行先输入n表示有n个叶子，接着输入n个数据表示n个叶子的权值，权值的顺序和前面输入的大写字母顺序对应

 以此类推输入下一棵二叉树

 输出
 输出每一棵二叉树的带权路径和

 样例输入
 2
 xA00tB00zC00D00
 4 7 6 2 3
 ab0C00D00
 2 10 20
 样例输出
 34
 40
 提示
 */

#include <iostream>
using namespace std;

class TreeNode {
public:
    TreeNode *leftChild;
    TreeNode *rightChild;
    char data;
    int weight;
    int deep;
    TreeNode() : leftChild(NULL), rightChild(NULL) {}
    ~TreeNode() {}
};

class BinTree {
    int pos;
    string strTree;
    TreeNode *createTree(int _deep) {
        TreeNode *T;
        char ch;
        ch = strTree[pos++];
        if (ch == '0') {
            T = NULL;
        } else {
            T = new TreeNode();
            T->data = ch;
            T->deep = _deep;
            _deep++;
            T->leftChild = createTree(_deep);
            T->rightChild = createTree(_deep);
        }
        return T;
    }

public:
    TreeNode *root;
    BinTree(string strTree) {
        this->strTree = strTree;
        pos = 0;
        int deep = 0;
        root = createTree(deep);
    }
};

int leaves;
int wt[10000];
int wtPos;
int weight;

void PreOrder(TreeNode *t) {
    if (t != NULL) {
        if ('A' <= t->data && t->data <= 'Z') {
            t->weight = wt[wtPos++];
            weight += t->weight * t->deep;
            //cout << t->data << " " << t->weight << " " << t->deep << endl;
        }
        PreOrder(t->leftChild);
        PreOrder(t->rightChild);
    }
}

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cin >> n;
        BinTree bt(s);
        leaves = n;
        wtPos = 0;
        weight = 0;
        for (int i = 0; i < n; i++) {
            cin >> wt[i];
        }
        PreOrder(bt.root);
        cout << weight << endl;
    }
    return 0;
}

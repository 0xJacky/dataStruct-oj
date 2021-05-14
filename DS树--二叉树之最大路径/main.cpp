//
//  main.cpp
//  DS树--二叉树之最大路径
//
//  Created by Jacky on 2021/5/10.
//

/*
 题目描述
 给定一颗二叉树的逻辑结构（先序遍历的结果，空树用字符‘0’表示，例如AB0C00D00），建立该二叉树的二叉链式存储结构
 二叉树的每个结点都有一个权值，从根结点到每个叶子结点将形成一条路径，每条路径的权值等于路径上所有结点的权值和。编程求出二叉树的最大路径权值。如下图所示，共有4个叶子即有4条路径，
 路径1权值=5 + 4 + 11 + 7 = 27          路径2权值=5 + 4 + 11 + 2 = 22
 路径3权值=5 + 8 + 13 = 26                路径4权值=5 + 8 + 4 + 1 = 18
 可计算出最大路径权值是27。
 该树输入的先序遍历结果为ABCD00E000FG00H0I00，各结点权值为：
 A-5，B-4，C-11，D-7，E-2，F-8，G-13，H-4，I-1
  
 输入
 第一行输入一个整数t，表示有t个测试数据
 第二行输入一棵二叉树的先序遍历，每个结点用字母表示
 第三行先输入n表示二叉树的结点数量，然后输入每个结点的权值，权值顺序与前面结点输入顺序对应
 以此类推输入下一棵二叉树
 输出
 每行输出每棵二叉树的最大路径权值，如果最大路径权值有重复，只输出1个
 样例输入
 2
 AB0C00D00
 4 5 3 2 6
 ABCD00E000FG00H0I00
 9 5 4 11 7 2 8 13 4 1
 样例输出
 11
 27
 */

#include <iostream>
using namespace std;

int wt[10000];
int weight;
int _max = 0;

class TreeNode {
public:
    TreeNode *leftChild;
    TreeNode *rightChild;
    char data;
    int weight;
    TreeNode() : leftChild(NULL), rightChild(NULL) {}
    ~TreeNode() {}
};

class BinTree {
    int pos;
    int wtPos;
    string strTree;
    int *weights;
    TreeNode *createTree(int sum = 0) {
        TreeNode *T;
        char ch;
        ch = strTree[pos++];
        if (ch == '0') {
            T = NULL;
        } else {
            T = new TreeNode();
            T->data = ch;
            sum += weights[wtPos++];
            _max = (_max > sum) ? _max : sum;
            T->leftChild = createTree(sum);
            T->rightChild = createTree(sum);
        }
        return T;
    }

public:
    TreeNode *root;
    BinTree(string strTree, int *weights) {
        this->weights = weights;
        this->strTree = strTree;
        pos = 0;
        wtPos = 0;
        root = createTree();
    }
};


int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cin >> n;
        weight = 0;
        for (int i = 0; i < n; i++) {
            cin >> wt[i];
        }
        BinTree bt(s, wt);
        cout << _max << endl;
        _max = 0;
    }
    return 0;
}

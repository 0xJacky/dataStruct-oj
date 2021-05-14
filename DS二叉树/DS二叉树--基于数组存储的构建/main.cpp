//
//  main.cpp
//  DS二叉树--基于数组存储的构建
//
//  Created by Jacky on 2021/4/27.
//

/*
 题目描述
 任意二叉树可以根据完全二叉树性质保存在一个数组中。已知二叉树的数组存储，用程序构建该二叉树。

 提示：用递归方法或非递归都可以

 递归方法的代码框架如下：

  



 输入
 第一行输入一个整数t，表示有t个测试数据

 第二行起输入二叉树的数组存储结果，空树用字符‘0’表示，输入t行

 数组的数据由大写字母和0表示

 输出
 逐行输出每个二叉树的先序结果

 样例输入
 3
 ABC0D
 ABCDEF000G
 ABEC0F0D0
 样例输出
 ABDC
 ABDEGCF
 ABCDEF
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
    int len;
    string strTree;
    TreeNode *createTree(int pos) {
        // 采用递归，在第pos位置建树
        // 用参数 pos 传递当前节点在数组的位置
        // 根据二叉树性质5，因为数组从0编号，父节点是i，则左右孩子的位置是2i+1和2i+2
        TreeNode *T; // 临时指针 T
        int ch;
        // 数组越界检查，检查pos如果超过数组长度，直接返回空
        if (pos >= len) return NULL;
        ch = strTree[pos];
        if (ch == '0') T = NULL;
        else {
            // 为节点T分配空间
            T = new TreeNode();
            // 将ch值放入T的data中
            T->data = ch;
            // 根据二叉树性质5创建左子树
            T->leftChild = createTree(2*pos+1);
            // 根据二叉树性质5创建右子树
            T->rightChild = createTree(2*pos+2);
        }
        return T;
    }

public:
    TreeNode *root;
    BinTree(string strTree) {
        this->strTree = strTree;
        len = (int)strTree.length();
        root = createTree(0);
    }
};


void PreOrder(TreeNode *t) {
    if (t != NULL) {
        cout << t->data;
        PreOrder(t->leftChild);
        PreOrder(t->rightChild);
    }
}

int main() {
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        BinTree bt(s);
        PreOrder(bt.root);
        cout << endl;
    }
    return 0;
}

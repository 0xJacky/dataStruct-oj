//
//  main.cpp
//  DS二叉树--基于数组存储的构建
//
//  Created by Jacky on 2021/4/27.
//

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

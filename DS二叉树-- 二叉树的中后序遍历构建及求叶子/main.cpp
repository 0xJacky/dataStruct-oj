//
//  main.cpp
//  DS二叉树-- 二叉树的中后序遍历构建及求叶子
//
//  Created by Jacky on 2021/5/10.
//

/*
 题目描述
 按中序遍历和后序遍历给出一棵二叉树，求这棵二叉树中叶子节点权值的最小值。

 输入保证叶子节点的权值各不相同。

 输入
 测试数据有多组
 对于每组测试数据，首先输入一个整数N (1 <= N <= 10000)，代表二叉树有N个节点，接下来的一行输入这棵二叉树中序遍历的结果，最后一行输入这棵二叉树后序遍历的结果
 输入一直处理到文件尾(EOF)

 输出
 对于每组测试数据，输出一个整数，代表二叉树中叶子节点权值最小值

 样例输入
 7
 3 2 1 4 5 7 6
 3 1 2 5 6 7 4
 8
 7 8 11 3 5 16 12 18
 8 3 11 7 16 18 12 5
 1
 255
 255
 样例输出
 1
 3
 255
 */

#include <iostream>
#include <limits.h>
using namespace std;
class BiTreeNode {
public:
    int data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode *parent;
    BiTreeNode() : LeftChild(NULL), RightChild(NULL), parent(NULL) {}
    ~BiTreeNode() {}
};
class BiTree {
    BiTreeNode *Root;
    int len;
    int *postorder;
    int *inorder;
    BiTreeNode *CreateTree(int left, int right, int rootPos) {
        if (right < left) return NULL;
        BiTreeNode *t = new BiTreeNode();
        int _root = 0;
        for (int i = left; i <= right; i++) {
            if (inorder[i] == postorder[rootPos]) {
                _root = i;
                break;
            }
        }
        t->data = postorder[rootPos];
        t->LeftChild = CreateTree(left, _root - 1, rootPos -  1 - right + _root);
        t->RightChild = CreateTree(_root+1, right, rootPos - 1);
        return t;
    }
    void minLeave(BiTreeNode *p, int *ans) {
        if (p) {
            if (p->LeftChild == NULL && p->RightChild == NULL) {
                if (p->data < *ans) *ans = p->data;
            }
            minLeave(p->LeftChild, ans);
            minLeave(p->RightChild, ans);
        }
    }

public:
    BiTree(int n, int *s1, int *s2);
    ~BiTree(){};
    void CreateTree() {
        Root = CreateTree(0, len-1, len - 1);
    }
    void minLeave(int *ans) {
        minLeave(Root, ans);
    }
    
};
BiTree::BiTree(int n, int *post, int *in) {
    len = n;
    postorder = post;
    inorder = in;
}

int main() {
    int n;
    while (cin >> n) {
        int *inorder, *postorder;
        inorder = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
        }
        postorder = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> postorder[i];
        }
        BiTree bt(n, postorder, inorder);
        bt.CreateTree();
        int ans = INT_MAX;
        bt.minLeave(&ans);
        cout << ans << endl;
    }
    return 0;
}


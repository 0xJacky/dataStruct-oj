//
//  main.cpp
//  DS二叉树--二叉树的中后序遍历及操作
//
//  Created by Jacky on 2021/5/9.
//

#include <iostream>
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
    int *pastorder;
    int *inorder;
    void *CreateTree(BiTreeNode *&p, int *pastorder, int *inorder, int l, BiTreeNode *parent) {
        BiTreeNode *t;
        int i, j;
        if (l) {
            int temp = pastorder[l - 1];  //后序遍历最后一位数为根节点
            p = new BiTreeNode();
            p->data = temp;
            p->parent = parent;
            for (i = 0; i < l; i++)
                if (inorder[i] ==
                    temp)  //在中序遍历中找到根结点，其左边的为左子树，右边为右子树
                    break;
            int num1 = i;          //左子树个数
            int num2 = l - i - 1;  //右子树个数
            int in1[num1], in2[num2];
            for (j = 0; j < l; j++) {
                if (j < i)
                    in1[j] = inorder[j];
                else if (j > i)
                    in2[j - i - 1] = inorder[j];
            }
            int post1[num1], post2[num2];
            for (j = 0; j < l; j++) {
                if (j < i)
                    post1[j] = pastorder[j];
                else if (j >= i && j < l - 1)
                    post2[j - i] = pastorder[j];
            }
            CreateTree(p->LeftChild, post1, in1, num1, p);
            CreateTree(p->RightChild, post2, in2, num2, p);
        } else
            t = NULL;
        
        return t;
    }

public:
    BiTree(int n, int *s1, int *s2);
    ~BiTree(){};
    void CreateTree() {
        CreateTree(Root, pastorder, inorder, len, NULL);
    }
    void UPDATE(int &a, int &b) {
        update(Root, a, b);
    }
    void update(BiTreeNode *p, int &a, int &b) {
        if (p) {
            update(p->LeftChild, a, b);
            a--;
            if (a == 0) p->data = b;
            update(p->RightChild, a, b);
        }
    }
    void QUERY() {
        query(Root);
    }
    int count(BiTreeNode *p) {
        int s = 0;
        while (p) {
            s = p->data + s;
            p = p->parent;
        }
        return s;
    }
    void query(BiTreeNode *p) {
        if (p) {
            query(p->LeftChild);
            cout << p->data << ' ' << count(p) << endl;
            query(p->RightChild);
        }
    }
};
BiTree::BiTree(int n, int *past, int *in) {
    len = n;
    pastorder = new int[len];
    inorder = new int[len];
    for (int i = 0; i < len; i++) {
        pastorder[i] = past[i];
        inorder[i] = in[i];
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int in[n], past[n];
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> past[i];
        }
        BiTree mytree(n, past, in);
        mytree.CreateTree();
        while (1) {
            string s;
            cin >> s;
            if (s == "UPDATE") {
                int a, b;
                cin >> a >> b;
                mytree.UPDATE(a, b);
            } else if (s == "QUERY") {
                mytree.QUERY();
            } else if (s == "STOP") {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}

//
//  main.cpp
//  DS二叉树--二叉搜索树模拟
//
//  Created by Jacky on 2021/5/27.
//

#include <iostream>
#include <sstream>
using namespace std;

class TreeNode {
public:
    long int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};

class BiTree {
    TreeNode *Root = NULL;
    long int size = 0;
    stringstream pre;
    stringstream in;
    stringstream post;
    void PreOrder(TreeNode *p) {
        if (p) {
            pre << p->data << ' ';
            PreOrder(p->left);
            PreOrder(p->right);
        }
    }
    
    void InOrder(TreeNode *p) {
        if (p) {
            InOrder(p->left);
            in << p->data << ' ';
            InOrder(p->right);
        }
    }
    
    void PostOrder(TreeNode *p) {
        if (p) {
            PostOrder(p->left);
            PostOrder(p->right);
            post << p->data << ' ';
        }
    }
    
    TreeNode *Insert_BST(TreeNode *T, long int data) {
        if (T==NULL) {
            T = new TreeNode();
            T->data = data;
            T->left = T->right = NULL;
        } else {
            if (data < T->data) {
                T->left = Insert_BST(T->left, data);
            } else {
                T->right = Insert_BST(T->right, data);
            }
            
        }
        return T;
    }
public:
    BiTree() {
        create_BST();
    }
    
    void create_BST() {
        long int d, n;
        //Root = new TreeNode();
        cin >> n;
        while (n--) {
            cin >> d;
            size++;
            Root = Insert_BST(Root, d);
        }
    }
    
    void Insert_BST(long int data) {
        Insert_BST(Root, data);
    }
    void PreOrder() {
        PreOrder(Root);
        long int s;
        for (int i = 0; i < size; i++) {
            pre >> s;
            cout << s;
            if (i != size - 1) {
                cout << ' ';
            }
        }
        cout << endl;
        
    }
    void InOrder() {
        InOrder(Root);
        long int s;
        for (int i = 0; i < size; i++) {
            in >> s;
            cout << s;
            if (i != size - 1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
    void PostOrder() {
        PostOrder(Root);
        long int s;
        for (int i = 0; i < size; i++) {
            post >> s;
            cout << s;
            if (i != size - 1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
};

int main() {
    long int t;
    cin >> t;
    while (t--) {
        BiTree bt;
        bt.PreOrder();
        bt.InOrder();
        bt.PostOrder();
        if (t) {
            cout << endl;
        }
    }
    return 0;
}

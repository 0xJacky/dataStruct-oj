//
//  main.cpp
//  DS二叉排序树之查找
//
//  Created by Jacky on 2021/5/18.
//

#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};

class BiTree {
    TreeNode *Root = NULL;
    void InOrder(TreeNode *p) {
        if (p) {
            InOrder(p->left);
            cout << p->data << " ";
            InOrder(p->right);
        }
    }
    
    TreeNode *Insert_BST(TreeNode *T, int data) {
        if (T==NULL) {
            T = new TreeNode();
            T->data = data;
            T->left = T->right = NULL;
        } else {
            if (T->data == data) {
                return NULL; // 已有节点
            } else if (data < T->data) {
                T->left = Insert_BST(T->left, data);
            } else {
                T->right = Insert_BST(T->right, data);
            }
            
        }
        return T;
    }
    void Find(bool *flag, TreeNode *t, int data, int *count) {
        if (!*flag && t) {
            (*count)++;
            if (t->data == data) {
                *flag = true;
                return; // 已有节点
            } else if (data < t->data) {
                Find(flag, t->left, data, count);
            } else {
                Find(flag, t->right, data, count);
            }
        }
    }
public:
    BiTree() {
        create_BST();
    }
    
    void create_BST() {
        int d, n;
        cin >> n;
        while (n--) {
            cin >> d;
            Root = Insert_BST(Root, d);
        }
    }
    
    void Insert_BST(int data) {
        Insert_BST(Root, data);
    }
    
    void Find(int data) {
        bool flag = false;
        int count = 0;
        Find(&flag, Root, data, &count);
        if (flag) {
            cout << count << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    
    void InOrder() {
        InOrder(Root);
        cout << endl;
    }
};

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        BiTree bt;
        bt.InOrder();
        
        cin >> n;
        while (n--) {
            cin >> tmp;
            bt.Find(tmp);
        }
    }
    return 0;
}

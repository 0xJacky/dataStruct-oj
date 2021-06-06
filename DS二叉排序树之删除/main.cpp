//
//  main.cpp
//  DS二叉排序树之删除
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
    TreeNode *parent = NULL;
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
    
    void FindParent(TreeNode *t, TreeNode *parent) {
        if (t) {
            t->parent = parent;
            FindParent(t->left, t);
            FindParent(t->right, t);
        }
    }

    void Del(TreeNode *t, int data) {
        if (t) {
            if (data == t->data) {
                return Delete(t);
            } else if (data < t->data) {
                Del(t->left, data);
            } else Del(t->right, data);
        }
    }
    void Delete(TreeNode *p) {
        TreeNode *s;
        if (!p->left && !p->right) {
            if (p->parent->left == p) p->parent->left = NULL;
            else p->parent->right = NULL;
            delete p;
        } else if (!p->right) {
            s = p->left; *p = *s; delete s;
        } else if (!p->left) {
            s = p->right; *p = *s; delete s;
        } else {
            s = p->left;
            while (s->right) {
                s = s->right;
            }
            
            p->data = s->data;
            if (s->parent != p) {
                s->parent->right = s->left;
            } else {
                p->left = s->left;
            }
            delete s;
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
    
    void Del(int data) {
        Del(Root, data);
    }
    
    void InOrder() {
        InOrder(Root);
        cout << endl;
    }
    
    void FindParent() {
        FindParent(Root, NULL);
    }
};

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        BiTree bt;
        bt.FindParent();
        bt.InOrder();
        
        cin >> n;
        while (n--) {
            cin >> tmp;
            bt.Del(tmp);
            bt.FindParent();
            bt.InOrder();
        }
    }
    return 0;
}

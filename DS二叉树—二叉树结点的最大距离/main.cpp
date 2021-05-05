//
//  main.cpp
//  DS二叉树—二叉树结点的最大距离
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
    int pos;
    string strTree;
    TreeNode *createTree(int _deep) {
        TreeNode *T;
        char ch;
        ch = strTree[pos++];
        if (ch == '#') {
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

struct Ans {
    int distence;
    char a;
    char b;
} ans;

// 找到该分支最深的叶子到本节点的距离的 data 存放在 data 中
// 最远距离存在 d 中
void PreOrderDistence(TreeNode *t, char *data, int parent_deep, int *d) {
    if (t != NULL) {
        if (t->deep - parent_deep > *d) {
            *data = t->data;
            *d = t->deep - parent_deep;
        }
        PreOrderDistence(t->leftChild, data, parent_deep, d);
        PreOrderDistence(t->rightChild, data, parent_deep, d);
    }
}

void PreOrder(TreeNode *t) {
    if (t != NULL) {
        char a;
        char b;
        int d1 = 0;
        int d2 = 0;
        PreOrderDistence(t->leftChild, &a, t->deep, &d1);
        PreOrderDistence(t->rightChild, &b, t->deep, &d2);
        if (d1 + d2 > ans.distence) {
            ans = {d1 + d2, a, b};
        }
        //cout << t->data << " " << t->deep << endl;
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
        ans = {0,0,0};
        PreOrder(bt.root);
        cout << ans.distence << ":";
        if (ans.distence) {
            cout << ans.a << " " << ans.b;
        }
        cout << endl;
    }
}

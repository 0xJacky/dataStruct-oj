//
//  main.cpp
//  DS树--带权路径和
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

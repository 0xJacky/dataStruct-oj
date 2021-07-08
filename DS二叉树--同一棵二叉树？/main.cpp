//
//  main.cpp
//  DS二叉树--同一棵二叉树？
//
//  Created by Jacky on 2021/6/30.
//

#include <iostream>
#include <string>
using namespace std;
class BiTreeNode {
public:
    int pos;
    char data;
    //结点数据
    BiTreeNode *LeftChild;
    //左子树指针
    BiTreeNode *RightChild;
    //右子树指针
    BiTreeNode() : LeftChild(NULL), RightChild(NULL) {}
    ~BiTreeNode() {}
};
class BiTree {
private:
    BiTreeNode *Root;
    //根结点指针
    int pos;
    string strTree;
    string arrTree;
    BiTreeNode *CreateBiTree(int);

public:
    bool eq = true;
    BiTree(){};
    //构造函数
    ~BiTree(){};
    //析构函数
    void CreateTree(string, string);  //利用先序遍历结果创建二叉树
};  //构造二叉树，利用先序遍历结果建树
void BiTree::CreateTree(string TreeArr, string TreeStr)  //公有函数，对外接口
{
    pos = 0;
    strTree.assign(TreeStr);
    arrTree.assign(TreeArr);
    Root = CreateBiTree(0);
}

BiTreeNode *BiTree::CreateBiTree(int arrPos)  //递归建树，私有函数，类内实现
{
    BiTreeNode *T;
    char ch;
    ch = strTree[pos++];
    if (pos>strTree.length()) return NULL;
    if (ch == '#')
        T = NULL;
    else {
        T = new BiTreeNode();
        T->data = ch;
       //cout << arrPos << ch << endl;
        if (arrTree[arrPos] != ch) {
            eq = false;
        }
        T->LeftChild = CreateBiTree(2 * arrPos + 1);   //构造左子树
        T->RightChild = CreateBiTree(2 * arrPos + 2);  //构造右子树
    }
    return T;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string arrTree, strTree;
        cin >> arrTree;
        cin >> strTree;
        BiTree bt;
        bt.CreateTree(arrTree, strTree);
        if (bt.eq) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

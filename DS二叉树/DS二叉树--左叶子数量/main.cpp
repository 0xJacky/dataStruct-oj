//
//  main.cpp
//  DS二叉树--左叶子数量
//
//  Created by Jacky on 2021/4/21.
//

/*
 题目描述
 计算一颗二叉树包含的叶子结点数量。

 左叶子是指它的左右孩子为空，而且它是父亲的左孩子

 提示：可以用三叉链表法，也可以用现有算法对两层结点进行判断

 建树方法采用“先序遍历+空树用0表示”的方法

 输入
 第一行输入一个整数t，表示有t个测试数据

 第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行

 输出
 逐行输出每个二叉树的包含的左叶子数量

 样例输入
 3
 AB0C00D00
 AB00C00
 ABCD0000EF000

 样例输出
 0
 1
 2
 提示
 */
#include <iostream>
#include <string>
using namespace std;
class BiTreeNode {
public:
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
    BiTreeNode *Root; //根结点指针
    int pos;
    int leaves = 0;
    string strTree;
    BiTreeNode *CreateBiTree();
    void PreOrder(BiTreeNode *t, bool flag = false);
    void InOrder(BiTreeNode *t);
    void PostOrder(BiTreeNode *t);

public:
    BiTree(){};
    //构造函数
    ~BiTree(){};
    //析构函数
    void CreateTree(string TreeArray);  //利用先序遍历结果创建二叉树
    void PreOrder(); //前序遍历
    void InOrder(); //中序遍历
    void PostOrder(); //后序遍历
    int getLeaves() {
        return leaves;
    }
};  //构造二叉树，利用先序遍历结果建树
void BiTree::CreateTree(string TreeArray)  //公有函数，对外接口
{
    pos = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree();
}

BiTreeNode *BiTree::CreateBiTree()  //递归建树，私有函数，类内实现
{
    BiTreeNode *T;
    char ch;
    ch = strTree[pos++];
    if (ch == '0')
        T = NULL;
    else {
        T = new BiTreeNode();
        T->data = ch;                    //生成根结点
        T->LeftChild = CreateBiTree();   //构造左子树
        T->RightChild = CreateBiTree();  //构造右子树
    }
    return T;
}

//定义先序遍历函数
void BiTree::PreOrder()  //公有函数，对外接口
{
    PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode *t, bool flag) {  //私有函数，类内实现
    //若结点t不空，执行以下操作
    if (t != NULL) {
        if (flag && t->LeftChild == NULL && t->RightChild == NULL) {
            leaves++;
        }
        //1、输出当前结点t的数据，表示t已访问
        //cout << t->data;
        //2、先序遍历t的左孩子
        PreOrder(t->LeftChild, true);
        //3、先序遍历t的右孩子
        PreOrder(t->RightChild);
    }
}
//定义中序遍历函数
void BiTree::InOrder()  //公有函数，对外接口
{
    InOrder(Root);
}
void BiTree::InOrder(BiTreeNode *t) {  //私有函数，类内实现
    //若结点t不空，执行以下操作
    if (t != NULL) {
        //1、中序遍历t的左孩子
        InOrder(t->LeftChild);
        //2、输出当前结点t的数据，表示t已访问
        cout << t->data;
        //3、中序遍历t的右孩子
        InOrder(t->RightChild);
    }
}
//后序遍历函数
void BiTree::PostOrder()  //公有函数，对外接口
{
    PostOrder(Root);
}
void BiTree::PostOrder(BiTreeNode *t) {  //私有函数，类内实现
    //若结点t不空，执行以下操作
    if (t != NULL) {
        //1、后序遍历t的左孩子
        PostOrder(t->LeftChild);
        //2、后序遍历t的右孩子
        PostOrder(t->RightChild);
        //3、输出当箭结点t的数据，表示t已访问
        cout << t->data;
    }
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        BiTree bt;
        bt.CreateTree(s);
        bt.PreOrder();
        cout << bt.getLeaves() << endl;
    }
    return 0;
}


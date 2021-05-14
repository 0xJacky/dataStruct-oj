//
//  main.cpp
//  DS二叉树—二叉树镜面反转
//
//  Created by Jacky on 2021/5/10.
//

#include <iostream>
using namespace std;

class BiTreeNode;

class queueNode {
public:
    BiTreeNode *node;
    queueNode *next;
};

class queue {
    int len;
    queueNode *frontNode;
    queueNode *LastNode;
public:
    queue(): frontNode(), len(0) {};
    void push(BiTreeNode *t) {
        if (len == 0) {
            frontNode = new queueNode();
            frontNode->node = t;
            LastNode = frontNode;
        } else {
            auto tmp = LastNode;
            tmp->next = new queueNode();
            tmp->next->node = t;
            LastNode = tmp->next;
        }
        len++;
    }
    bool empty() {
        return len == 0;
    }
    BiTreeNode* front() {
        return frontNode->node;
    }
    void pop() {
        auto tmp = frontNode;
        frontNode = frontNode->next;
        if (tmp) {
            delete tmp;
            len--;
        }
    }
};

class BiTreeNode {
public:
    BiTreeNode * LeftChild;
    BiTreeNode * RightChild;
    char data;
    int tag;
    BiTreeNode(): LeftChild(NULL), RightChild(NULL), data('\0') {}
    BiTreeNode(int t): LeftChild(NULL), RightChild(NULL), tag(t) {}
};

class BiTree {
    char * strTree;
    int pos;
    BiTreeNode * Root;
    BiTreeNode * CreateTree() {
        BiTreeNode *T;
        char ch;
        ch = strTree[pos++];
        if (ch == '#')
            T = NULL;
        else {
            T = new BiTreeNode();
            T->data = ch;                    //生成根结点
            T->RightChild = CreateTree();   //构造左子树
            T->LeftChild = CreateTree();  //构造右子树
        }
        return T;
    }
    void PreOrder(BiTreeNode *t) {
        //若结点t不空，执行以下操作
        if (t != NULL) {
            //1、输出当前结点t的数据，表示t已访问
            cout << t->data << ' ';
            //2、先序遍历t的左孩子
            PreOrder(t->LeftChild);
            //3、先序遍历t的右孩子
            PreOrder(t->RightChild);
        }
    }
    void InOrder(BiTreeNode * t) {
        //私有函数，类内实现
            //若结点t不空，执行以下操作
            if (t != NULL) {
                //1、中序遍历t的左孩子
                InOrder(t->LeftChild);
                //2、输出当前结点t的数据，表示t已访问
                cout << t->data << ' ';
                //3、中序遍历t的右孩子
                InOrder(t->RightChild);
            }
    }
    void PostOrder(BiTreeNode * t) {
        //私有函数，类内实现
            //若结点t不空，执行以下操作
            if (t != NULL) {
                //1、后序遍历t的左孩子
                PostOrder(t->LeftChild);
                //2、后序遍历t的右孩子
                PostOrder(t->RightChild);
                //3、输出当箭结点t的数据，表示t已访问
                cout << t->data << ' ';
            }
    }
    void LevelOrder(BiTreeNode * t) {
        queue tq;
        BiTreeNode *p = t;
        // 设 p 是指向当前节点的指针变量，如果 p 不空，p 入队，然后执行以下循环
        if (p) {
            tq.push(p);
            // 当队列不空
            while (!tq.empty()) {
                // 把队首元素出队到p，注意这里代码不止1行
                p = tq.front();
                tq.pop();
                // 输出 p 的数据，表示p已遍历
                if (p) {
                    cout << p->data << ' ';
                    // 把 p 的左右节点以此入队
                    tq.push(p->LeftChild);
                    tq.push(p->RightChild);
                }
            }
        }
    }
public:
    void PreOrder() {
        if (!Root) {
            cout << "NULL" << endl;
            return;
        }
        PreOrder(Root);
        cout << endl;
    }
    void InOrder() {
        if (!Root) {
            cout << "NULL" << endl;
            return;
        }
        InOrder(Root);
        cout << endl;
    }
    void PostOrder() {
        if (!Root) {
            cout << "NULL" << endl;
            return;
        }
        PostOrder(Root);
        cout << endl;
    }
    void LevelOrder() {
        if (!Root) {
            cout << "NULL" << endl;
            return;
        }
        LevelOrder(Root);
        cout << endl;
    }
    void CreateTree(char * strTree) {
        this->strTree = strTree;
        pos = 0;
        Root = CreateTree();
    }
};

char strTree[100000];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> strTree;
        BiTree bi;
        bi.CreateTree(strTree);
        bi.PreOrder();
        bi.InOrder();
        bi.PostOrder();
        bi.LevelOrder();
    }
    return 0;
}

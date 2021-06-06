//
//  main.cpp
//  DS二叉平衡树构建
//
//  Created by Jacky on 2021/5/26.
//

#include <iostream>
using namespace std;

#define LH 1 // 左高
#define EH 0 // 等高
#define RH -1 // 右高

class BiNode
{
    public:
        int key; // 关键值
        int bf; // 平衡因子
        BiNode *lChild, *rChild;
        BiNode() {};
        BiNode(int kValue, int bValue)
       {

           key = kValue;
           bf = bValue;
           lChild = NULL;
           rChild = NULL;
       }

       ~BiNode()
      {
           key = 0;
           bf = 0;
           lChild = NULL;
           rChild = NULL;
       }
};

// 二叉排序树
class BST
{
     private:
         BiNode *root; // 根结点指针
         void rRotate(BiNode *&p);
         void lRotate(BiNode *&p);
         void leftBalance(BiNode *&t);
         void rightBalance(BiNode *&t);
         int insertAVL(BiNode *&t, int key, bool &taller); // 插入元素并做平衡处理
         void inOrder(BiNode *p);
     public:
         BST();
         void insertAVL(int key); // 二叉排序树插入元素
         ~BST();
         void inOrder(); // 中序遍历
};

// 以p为根的二叉排序树作右旋处理
void BST::rRotate(BiNode *&p)
{
    // 参考课本236页算法9.9
    auto lc = p->lChild;
    p->lChild = lc->rChild;
    lc->rChild = p;
    p = lc;
}

// 以p为根的二叉排序树作左旋处理
void BST::lRotate(BiNode *&p)
{
    // 参考课本236页算法9.10
    auto rc = p->rChild;
    p->rChild = rc->lChild;
    rc->lChild = p;
    p = rc;
}

// t为根的二叉排序树作左平衡旋转处理
void BST::leftBalance(BiNode*& t)
{
    BiNode* l, * lr;
    l = t->lChild;
    switch (l->bf)
    {
    case LH:
        t->bf = l->bf = EH;
        rRotate(t);
        break;
    case RH:
        lr = l->rChild;
        switch (lr->bf)
        {
        case LH:
            t->bf = RH;
            l->bf = EH;
            break;
        case EH:
            t->bf = l->bf = EH;
            break;
        case RH:
            t->bf = EH;
            l->bf = LH;
            break;
        }
        lr->bf = EH;
        lRotate(t->lChild);
        rRotate(t);
    }
}

// t为根的二叉排序树作右平衡旋转处理
void BST::rightBalance(BiNode *&t)
{
     // 参考课本238页算法9.12
    auto rc = t->rChild;
    switch (rc->bf) {
        case RH:
            t->bf = rc->bf = EH;
            lRotate(t);
            break;
        
        case LH:
            auto rl = rc->lChild;
            switch (rl->bf) {
                case RH:
                    t->bf = LH;
                    rc->bf = EH;
                    break;
                
                case EH:
                    t->bf = rc->bf = EH;
                    break;
                
                case LH:
                    t->bf = EH;
                    rc->bf = RH;
                    break;
            }
            rl->bf = EH;
            rRotate(t->rChild);
            lRotate(t);
    }
}


int BST::insertAVL(BiNode*& t, int key, bool& taller)
{
    if (!t)
    {
        t = new BiNode;
        t->key = key;
        t->lChild = t->rChild = NULL;
        t->bf = EH;
        taller = true;
    }
    else
    {
        if (key == t->key)
        {
            taller = false;
            return false;
        }
        if (key < t->key)
        {
            if (!insertAVL(t->lChild, key, taller))
                return false;
            if (taller)
            {
                switch (t->bf)
                {
                case LH:
                    leftBalance(t);
                    taller = false;
                    break;
                case EH:
                    t->bf = LH;
                    taller = true;
                    break;
                case RH:
                    t->bf = EH;
                    taller = false;
                    break;
                }
            }
        }
        else {
            if (!insertAVL(t->rChild, key, taller))
                return false;
            if (taller)
            {
                switch (t->bf)
                {
                case LH:
                    t->bf = EH;
                    taller = false;
                    break;
                case EH:
                    t->bf = RH;
                    taller = true;
                    break;
                case RH:
                    rightBalance(t);
                    taller = false;
                    break;
                }
            }
        }
    }
    return true;
}

void BST::inOrder(BiNode *p)
{
    if(p)
    {
        inOrder(p->lChild);
        cout << p->key << ':' << p->bf << ' ';
        inOrder(p->rChild);
    }

    return;
}

// 二叉排序树初始化
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root = NULL;
}

// 插入元素并作平衡处理
void BST::insertAVL(int key)
{
    bool taller = false;
    insertAVL(root, key, taller);
}


// 中序遍历
void BST::inOrder()
{
    inOrder(root);
}

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        // 构建二叉平衡树，并在插入元素时做平衡处理
        int n, elem;
        cin >> n;
        BST tree;
        while(n--)
        {
           cin >> elem;
           tree.insertAVL(elem);
        }
        tree.inOrder();
        cout << endl;
    }

    return 0;
}


//
//  main.cpp
//  DS B-树构建及查找
//
//  Created by Jacky on 2021/6/9.
//

#define N 100
#include <iostream>
#include <queue>
using namespace std;

int m;

class BTNode {
public:
    int keyNum;      // 关键字个数
    BTNode *parent;  // 指向双亲结点
    int *keys;       // 关键字向量
    BTNode **ptr;    // 子树指针向量
    BTNode() {
        keyNum = 0;
        parent = NULL;
        keys = new int[m + 2];
        ptr = new BTNode *[m + 2];
        for (int i = 0; i < m + 2; i++) ptr[i] = nullptr;
    }

    ~BTNode() {
        keyNum = 0;
        parent = NULL;
        delete[] keys;
        delete[] ptr;
    }
};

class Result {
public:
    BTNode *pt;  // 指向找到的结点
    int i;
    int tag;
    Result(BTNode *p, int m, int t) {
        pt = p;
        i = m;
        tag = t;
    }

    ~Result() {
        pt = NULL;
        i = 0;
        tag = 0;
    }
};

class BTree {
private:
    BTNode *root;
    void insert(BTNode *t, int i, int k,
                BTNode *ap);  // 将k和ap分别插入t->key[i+1]和t->ptr[i + 1]
    int search(BTNode *t, int k);  // 在p->key[1...keynum]中查找 k
    void split(BTNode *q, int s,
               BTNode *&ap);  // 将q->key[s+1...m],q->ptr[s...m]移入新结点ap
    void newRoot(
        BTNode *&t, BTNode *q, int x,
        BTNode *ap);  // 生成含信息(t, x, ap)的新根结点t*ap, 原t和 ap为子树指针
    void insertBT(BTNode *&t, int k, BTNode *q,
                  int i);  // 在结点t的子结点q的key[i]与key[i+1]之间插入k
    Result *searchBT(BTNode *t, int k);  // 在结点t中查找k
public:
    BTree();
    ~BTree();
    void insertBT(int key);  // B-树插入操作
    void searchBT(int key);  // B-树查找操作
    void levelOrder();       // B-树层次遍历
};

// 将k和ap分别插入t->key[i+1]和t->ptr[i + 1]
void BTree::insert(BTNode* t, int i, int k, BTNode* ap) {
    t->keyNum++;
    for (int j = t->keyNum; j > i + 1; j--) {    //把[i+1, keyNum]的数据后移一位
        t->keys[j] = t->keys[j - 1];
        t->ptr[j] = t->ptr[j - 1];
    }
    t->keys[i + 1] = k;    //插入数据
    t->ptr[i + 1] = ap;
}

// 在p->key[1...keynum]中查找 k
int BTree::search(BTNode* t, int k) {
    for (int i = 1; i <= t->keyNum; i++)
        if (t->keys[i] >= k)
            return i - 1;    //找到关键字>=k，如果=则找到，如果>则在左边的子树找，或在i处插入
    return t->keyNum;    //所有关键字都<k，去最右侧边的子树找，或在keyNum处插入
}

// 将q->key[s+1...m],q->ptr[s...m]移入新结点ap
void BTree::split(BTNode* q, int s, BTNode*& ap) {
    ap = new BTNode;
    int j = 1;
    // 将q->key[s+1...m],q->ptr[s...m]移入新结点ap
    for (int i = s + 1; i <= q->keyNum; i++) {
        ap->keys[j] = q->keys[i];
        ap->ptr[j] = q->ptr[i];
        j++;
    }
    ap->ptr[0] = q->ptr[s];
    ap->keyNum = j - 1;
    q->keyNum -= j;
    ap->parent = q->parent;
    for (int i = 0; i <= ap->keyNum; i++)
        if (ap->ptr[i])
            ap->ptr[i]->parent = ap;
}

// 生成含信息(t, x, ap)的新根结点t, 原t和 ap为子树指针
void BTree::newRoot(BTNode*& t, BTNode* q, int x, BTNode* ap) {
    q = new BTNode;
    q->keyNum = 1;
    q->keys[1] = x;
    q->ptr[0] = t;
    q->ptr[1] = ap;
    t->parent = q;
    ap->parent = q;
    this->root = q;
}

// 遍历所有节点查询key关键字
Result *BTree::searchBT(BTNode* t, int k) {
    BTNode* p = t, * q = nullptr; // p指向当前查询节点，q指向当前节点的父节点
    bool found = false;
    int i = 0;
    while (p && !found) {
        i = search(p, k);    // 在当前节点中查找k
        if (p->keys[i + 1] == k)
            found = true;
        else {
            q = p;
            p = p->ptr[i];    // 转到下一个节点
        }
    }
    if (found)
        return new Result(p, i + 1, 1);    // 查找成功，返回节点信息
    else
        return new Result(q, i, 0);    // 查找失败，返回插入位置信息
}

// 参考课本244页算法9.14
void BTree::insertBT(BTNode*& t, int k, BTNode* q, int i) {
    int x = k;
    BTNode* ap = nullptr;
    bool finished = false;
    if (!q) {    // 创建第一个节点
        q = new BTNode;
        q->keyNum = 1;
        q->keys[1] = k;
        this->root = q;
        return;
    }
    while (!finished) {
        insert(q, i, x, ap);    // 将k和ap分别插入t->key[i+1]和t->ptr[i + 1]
        if (q->keyNum < m)    // 插入完成（keys从1开始，所以判断keyNum < m）
            finished = true;
        else {    // 分裂节点*q
            int s = (m + 1) / 2;    // 向上取整
            split(q, s, ap);    // 将q->key[s+1...m],q->ptr[s...m]移入新结点ap
            x = q->keys[s];
            q = q->parent;
            if (q)
                i = search(q, x);    //查找在父节点的插入位置
            else {
                newRoot(t, q, x, ap);
                finished = true;
            }
        }
    }
}

// B树初始化
BTree::BTree() {
    root = NULL;
}

BTree::~BTree() {
    root = NULL;
}

// B-树插入操作
void BTree::insertBT(int key) {
    Result *r = searchBT(root, key);
    if (!r->tag) {
        insertBT(root, key, r->pt, r->i);
    }
    return;
}

// B-树查找操作
void BTree::searchBT(int key) {
    Result *r = searchBT(root, key);
    if (!r->tag) {
        cout << "-1" << endl;
    } else {
        BTNode *p = r->pt;
        cout << p->keys[1];
        for (int i = 2; i <= p->keyNum; i++) {
            cout << ':' << p->keys[i];
        }
        cout << ' ' << r->i << endl;
    }
    return;
}

// B-树层次遍历输出关键字
void BTree::levelOrder() {
    queue<BTNode *> tq;
    BTNode *p = root;
    // 首结点入队
    if (p) {
        tq.push(p);
    }
    // 层次遍历树
    while (!tq.empty()) {
        p = tq.front();
        tq.pop();
        // 输出结点p的key
        cout << p->keys[1];
        for (int i = 2; i <= p->keyNum; i++) {
            cout << ':' << p->keys[i];
        }
        cout << ' ';
        // 自结点入栈
        for (int i = 0; i <= p->keyNum; i++) {
            if (!p->ptr[i]) {
                break;
            }
            tq.push(p->ptr[i]);
        }
    }
    return;
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        cin >> m;
        int n, k, key;
        // 构建B-树
        cin >> n;
        BTree bTree;
        while (n--) {
            cin >> key;
            bTree.insertBT(key);
        }
        // 按层次遍历输出B-树
        bTree.levelOrder();
        cout << endl;
        // 查找B-树结点
        cin >> k;
        while (k--) {
            cin >> key;
            bTree.searchBT(key);
        }
    }
    return 0;
}

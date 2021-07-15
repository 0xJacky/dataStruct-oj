#include <iostream>
#include <queue>
using namespace std;
   
int m;
   
class BTNode
{
public:
    int keyNum;
    BTNode* parent;
    int* keys;
    BTNode** ptr;
    BTNode()
    {
        keyNum = 0;
        parent = NULL;
        keys = NULL;
        ptr = NULL;
        keys = new int[m+1];
        for (int i = 0; i <= m; i++)keys[i] = -1;
        ptr = new BTNode * [m+1];
        for (int i = 0; i <= m; i++)ptr[i] = NULL;
    }
   
    ~BTNode()
    {
        keyNum = 0;
        parent = NULL;
        keys = NULL;
        ptr = NULL;
    }
};
   
class Result
{
public:
    BTNode* pt;
    int i;
    int tag;
    Result(BTNode* p, int m, int t)
    {
        pt = p;
        i = m;
        tag = t;
    }
   
    ~Result()
    {
        pt = NULL;
        i = 0;
        tag = 0;
    }
};
   
class BTree
{
private:
    BTNode* root;
    void insert(BTNode* t, int i, int k, BTNode* ap);
    int search(BTNode* t, int k);
    void split(BTNode* q, int s, BTNode*& ap);
    void newRoot(BTNode*& t, BTNode* q, int x, BTNode* ap);
    void insertBT(BTNode*& t, int k, BTNode* q, int i);
    Result* searchBT(BTNode* t, int k);
public:
    BTree();
    ~BTree();
    void insertBT(int key);
    void searchBT(int key);
    void levelOrder();
};
   
void BTree::insert(BTNode* t, int i, int k, BTNode* ap)
{
    if (t) {
        if (t->keys[i + 1] != -1) {
            for (int j = t->keyNum; j >= i + 1; j--) {
                t->keys[j + 1] = t->keys[j];
                t->ptr[j + 1] = t->ptr[j];
            }
               
        }
           
        if (ap)ap->parent = t;
            t->keyNum++;
            t->keys[i + 1] = k;
            t->ptr[i+1] = ap;
           
    }
   
}
   
int BTree::search(BTNode* t, int k)
{
    int i = 0;
    for (i; i < t->keyNum && k >= t->keys[i + 1]; i++);
       
    return i;
 
}
   
void BTree::split(BTNode* q, int s, BTNode*& ap)
{
    ap = new BTNode();
       
   
    for (int i = s + 2 , j = 1; i <= m; i++, j++) {
        ap->keys[j] = q->keys[i];
        q->keys[i] = -1;
        ap->keyNum++;
        q->keyNum--;
    }
    for (int i = s + 1 , j = 0; i <= m; i++, j++) {
        ap->ptr[j] = q->ptr[i];
        q->ptr[i] = NULL;
    }
  
}
   
void BTree::newRoot(BTNode*& t, BTNode* q, int x, BTNode* ap)
{
    if (t) {
   
           
        BTNode* k = new BTNode();
        k->ptr[0] = t;
        k->ptr[1] = ap;
        t->parent = ap->parent = k;
        k->keys[k->keyNum+1] = x;
           
        k->keyNum++;
        t = k;
    }
    else {
        t = new BTNode();
        t->keyNum++;
        t->keys[1] = x;
        t->ptr[0] = ap;
    }
 
}
   
Result* BTree::searchBT(BTNode* t, int k)
{
    BTNode* p = t;
    BTNode* q = NULL;
    bool found = false;
    int i = 0;
    while (p != NULL && found == false) {
        i = search(p, k);
        if (i > 0 && p->keys[i] == k)found = true;
        else { q = p; p = p->ptr[i]; }
    }
    Result* r = new Result(p, i, 1);
    if (found);
    else {
        r->pt = q;
        r->tag = 0;
    }
   
    return r;
}
   
void BTree::insertBT(BTNode*& t, int k, BTNode* q, int i)
{
    int x = k; BTNode* ap = NULL; bool finished = false;
    while (q && !finished) {
        insert(q, i, x, ap);
        if (q->keyNum < m)finished = true;
        else {
            int s = m / 2;
            split(q, s, ap);
            x = q->keys[s+1];
            q->keyNum--;
            q->keys[s + 1] = -1;
            q = q->parent;
            if (q)
                i = search(q, x);
        }
    }
    if (!finished)newRoot(t, q, x, ap);
}
   
 
BTree::BTree()
{
    root = NULL;
}
   
BTree::~BTree()
{
    root = NULL;
}
   
void BTree::insertBT(int key)
{
    Result* r = searchBT(root, key);
    if (!r->tag)
    {
        insertBT(root, key, r->pt, r->i);
    }
    return;
}
   
void BTree::searchBT(int key)
{
    Result* r = searchBT(root, key);
    if (!r->tag)
    {
        cout << "-1" << endl;
    }
    else
    {
        BTNode* p = r->pt;
   
        cout << p->keys[1];
        for (int i = 2; i <= p->keyNum; i++)
        {
            cout << ':' << p->keys[i];
        }
        cout << ' ' << r->i << endl;
   
    }
   
    return;
}
   
void BTree::levelOrder()
{
    queue<BTNode*> tq;
    BTNode* p = root;
    if (p)
    {
        tq.push(p);
    }
    while (!tq.empty())
    {
        p = tq.front();
        tq.pop();
        cout << p->keys[1];
        for (int i = 2; i <= p->keyNum; i++)
        {
            if(p->keys[i]!=-1){cout << ':' << p->keys[i]; }
        }
        cout << ' ';
        for (int i = 0; i < m; i++)
        {
            if (!p->ptr[i])
            {
                break;
            }
            tq.push(p->ptr[i]);
        }
    }
    return;
}
   
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m;
        int n, k, key;
        cin >> n;
        BTree bTree;
        while (n--)
        {
            cin >> key;
            bTree.insertBT(key);
        }
        bTree.levelOrder();
        cout << endl;
        cin >> k;
        while (k--)
        {
            cin >> key;
            bTree.searchBT(key);
        }
    }
    return 0;
}

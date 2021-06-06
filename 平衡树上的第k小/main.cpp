//
//  main.cpp
//  平衡树上的第k小
//
//  Created by Jacky on 2021/5/27.
//

#include <iostream>
using namespace std;
const int maxn = (int)1e5 + 10;
struct Node
{
    int key = -1;    // 关键值
    int data = -1;   // 携带的数据
    int left = -1;   // 左子树地址（数组下标）
    int right = -1;  // 右子树地址（数组下标）
    int height = -1; // 当前结点为根的子树高度
    int left_count = -1, right_count = -1;
    void Init() {}
    void Init(int _k, int _d = 0)
    {
        Init();
        key = _k;
        data = _d;
    }
    Node() { Init(); }
    Node(int k_, int d_ = 0) { Init(k_, d_); }
};
  
Node tr[maxn];
int root, tp; // root标记根节点位置，tp全局结点分配下标
  
inline int UpdateHeight(int now)
{
    // 更新 tr[now] 结点的子树高度，即tr[now].height的值
    int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    tr[now].left_count = tr[now].left == -1 ? 0 : tr[tr[now].left].left_count + tr[tr[now].left].right_count + 1;
    tr[now].right_count = tr[now].right == -1 ? 0 : tr[tr[now].right].left_count + tr[tr[now].right].right_count + 1;
    return tr[now].height = (lh > rh ? lh : rh) + 1;
}
inline int HeightDiff(int now)
{
    // 计算 tr[now] 结点的平衡因子
    int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    return lh - rh;
}
int LL(int an)
{
    int bn = tr[an].left;
    int dn = tr[bn].right;
    tr[bn].right = an;
    tr[an].left = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
}
int RR(int an)
{
    int bn = tr[an].right;
    int dn = tr[bn].left;
    tr[bn].left = an;
    tr[an].right = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
}
int LR(int an)
{
    tr[an].left = RR(tr[an].left);
    return LL(an);
}
int RL(int an)
{
    tr[an].right = LL(tr[an].right);
    return RR(an);
}
void Insert(int &now, int key, int data = 0)
{
    if (now == -1)
    {
        now = ++tp;
        tr[now].Init(key, data);
    }
    else if (key < tr[now].key)
    {
        Insert(tr[now].left, key, data);
        if (HeightDiff(now) == 2)
            now = (key < tr[tr[now].left].key ? LL(now) : LR(now));
    }
    else if (key > tr[now].key)
    {
        Insert(tr[now].right, key, data);
        if (HeightDiff(now) == -2)
            now = (key > tr[tr[now].right].key ? RR(now) : RL(now));
    }
    UpdateHeight(now);
}
void Delete(int &now, int key)
{
    if (now == -1)
        return;
    else if (key < tr[now].key)
        Delete(tr[now].left, key);
    else if (key > tr[now].key)
        Delete(tr[now].right, key);
    else
    {
        // 删除当前结点
        if (tr[now].left == -1)
            now = tr[now].right;
        else if (tr[now].right == -1)
            now = tr[now].left;
        else
        {
            int nd;
            for (nd = tr[now].left;; nd = tr[nd].right)
                if (tr[nd].right == -1)
                    break;
            tr[now].key = tr[nd].key;
            tr[now].data = tr[nd].data;
            Delete(tr[now].left, tr[nd].key);
        }
    }
    // 处理树平衡
    if (now == -1)
        return;
    UpdateHeight(now);
    if (HeightDiff(now) == 2)
        now = (HeightDiff(tr[now].left) >= 0 ? LL(now) : LR(now));
    else if (HeightDiff(now) == -2)
        now = (HeightDiff(tr[now].right) <= 0 ? RR(now) : RL(now));
}
  
int search(int now, int k)
{
    if (now == -1)
        return -1;
    if (tr[now].left_count + 1 > k)
        return search(tr[now].left, k);
    else if (tr[now].left_count + 1 < k)
        return search(tr[now].right, k - (tr[now].left_count + 1));
    else
    {
        int res = tr[now].key;
        Delete(root, tr[now].key);
        return res;
    }
}

int main() {
    int n, op, key;
    while (scanf("%d", &n) != EOF) {
        for (root = tp = -1; n--;)  // 初始化根结点和“内存指针”
        {
            cin >> op;
            if (op == 1) {
                cin >> key;
                Insert(root, key);
            } else if (op == 2) {
                cin >> key;
                cout << search(root, key) << endl;
            }
        }
        return 0;
    }
}

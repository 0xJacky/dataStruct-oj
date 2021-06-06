//
//  main.cpp
//  二叉平衡树练习
//
//  Created by Jacky on 2021/5/26.
//

#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
struct Node {
    int key;     // 关键值
    int data;    // 携带的数据
    int left;    // 左子树地址（数组下标）
    int right;   // 右子树地址（数组下标）
    int height;  // 当前结点为根的子树高度
    void Init() {
        data = key = left = right = height = -1;
    }
    void Init(int k_, int d_ = 0) {
        Init();
        key = k_;
        data = d_;
    }
    Node() {
        Init();
    }
    Node(int k_, int d_ = 0) {
        Init(k_, d_);
    }
};

Node tr[maxn];
int root, tp;  // root标记根节点位置，tp全局结点分配下标

inline int UpdateHeight(int now) {
    // 更新 tr[now] 结点的子树高度，即tr[now].height的值
    int leftHeight = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rightHeight = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    return tr[now].height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
inline int HeightDiff(int now) {
    // 计算 tr[now] 结点的平衡因子
    int leftHeight = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rightHeight = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    return leftHeight - rightHeight;
}

int LL(int an) {
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

void Insert(int &now, int key, int data = 0) {
    if (now == -1) {
        // 传入指针为空，新建结点保存数据
        now = ++tp;
        tr[now].Init(key, data);
    }
    // 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
    else {
        if (key < tr[now].key)
                {
                    Insert(tr[now].left, key, data);
                    int t = HeightDiff(now);
                    if (t > 1)
                    {
                        if (key < tr[tr[now].left].key)
                        {
                            now = LL(now);
                        }
                        else
                        {
                            now = LR(now);
                        }
                    }
                }
                else
                {
                    Insert(tr[now].right, key, data);
                    int t = HeightDiff(now);
                    if (t < -1)
                    {
                        if (key < tr[tr[now].right].key)
                        {
                            now = RL(now);
                        }
                        else
                        {
                            now = RR(now);
                        }
                    }
                }
    }
    UpdateHeight(now);
}

int GetFirst(int now)
{
    if (now == -1 || tr[now].left == -1) return now;
    return GetFirst(tr[now].left);
}

int GetLast(int now)
{
    if (now == -1 || tr[now].right == -1)return now;
    return GetLast(tr[now].right);
}

void Delete(int& now, int key)
{
    if (now == -1) return;
    else if (key < tr[now].key) Delete(tr[now].left, key);
    else if (key > tr[now].key) Delete(tr[now].right, key);
    else
    {
        if (tr[now].left == -1) now = tr[now].right;
        else if (tr[now].right == -1) now = tr[now].left;
        else
        {
            int t = GetLast(tr[now].left);
            tr[now].data = tr[t].data;
            tr[now].key = tr[t].key;
            Delete(tr[now].left, tr[now].key);
        }
    }
    if (now == -1) return;
    UpdateHeight(now);
    if (HeightDiff(now) > 1)
    {
        now = HeightDiff(tr[now].left) >= 0 ? LL(now) : LR(now);
    }
    else if (HeightDiff(now) < -1)
    {
        now = HeightDiff(tr[now].right) <= 0 ? RR(now) : RL(now);
    }
 
}

int find(int now, int key)
{
    while (now != -1 && tr[now].key != key)
    {
        if (key > tr[now].key)
        {
            now = tr[now].right;
        }
        else if (key < tr[now].key)
        {
            now = tr[now].left;
        }
    }
    return now;
}

int main() {
    int n, op, key, data;
    while (scanf("%d", &n) != EOF) {
        for (root = tp = -1; n--;)  // 初始化根结点和“内存指针”
        {
            scanf("%d", &op);
                        if (op == 1)
                        {
                            cin >> data >> key;
                            Insert(root, key, data);
                        }
                        else if (op == 2)
                        {
                            int ith = GetLast(root);
                            printf("%d\n", ith == -1 ? 0 : tr[ith].data);
                            if (ith != -1)Delete(root, tr[ith].key);
                        }
                        else if (op == 3)
                        {
                            int ith = GetFirst(root);
                            printf("%d\n", ith == -1 ? 0 : tr[ith].data);
                            if (ith != -1) Delete(root, tr[ith].key);
                        }
                        else
                        {
                            cin >> key;
                            int ith = find(root, key);
                            printf("%d\n", ith == -1 ? 0 : tr[ith].data);
                            if (ith != -1) Delete(root, tr[ith].key);
                        }
        }
        return 0;
    }
}

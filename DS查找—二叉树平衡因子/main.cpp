//
//  main.cpp
//  DS查找—二叉树平衡因子
//
//  Created by Jacky on 2021/5/19.
//

#include <iostream>
#include <string>
using namespace std;
class BiTree {
private:
    int length;
    char *arrayTree;

public:
    BiTree(){};
    //构造函数
    ~BiTree(){};
    //析构函数
    void CreateTree(char TreeArray[], int);  //利用先序遍历结果创建二叉树
    int PostOrder(int);
};  //构造二叉树，利用先序遍历结果建树
void BiTree::CreateTree(char *TreeArray, int length)  //公有函数，对外接口
{
    this->length = length;
    arrayTree = TreeArray;
}

int BiTree::PostOrder(int p) {
    if (p >= length) {
        return 0;
    }
    char data = arrayTree[p];
    int l = PostOrder(2 * p + 1);
    int r = PostOrder(2 * p + 2);
    if (data != '0') {
        cout << data << " " << l - r << endl;
    } else {
        return 0;
    }
    return max(l, r) + 1;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        char *treeArray = new char[n];
        for (int i = 0; i < n; i++) {
            cin >> treeArray[i];
        }
        BiTree bt;
        bt.CreateTree(treeArray, n);
        bt.PostOrder(0);
        delete[] treeArray;
    }
    return 0;
}

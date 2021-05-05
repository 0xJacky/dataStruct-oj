//
//  main.cpp
//  DS二叉树——二叉树之数组存储
//
//  Created by Jacky on 2021/4/21.
//

#include <iostream>
#include <string>
using namespace std;
class BiTree {
private:
    int length;
    int *arrayTree;

public:
    BiTree(){};
    //构造函数
    ~BiTree(){};
    //析构函数
    void CreateTree(int TreeArray[], int);  //利用先序遍历结果创建二叉树
    void PreOrder(int);
 
};  //构造二叉树，利用先序遍历结果建树
void BiTree::CreateTree(int *TreeArray, int length)  //公有函数，对外接口
{
    this->length = length;
    arrayTree = TreeArray;
}

void BiTree::PreOrder(int p) {
    if (p >= length) {
        return;
    }
    int data = arrayTree[p];
    
    if (data != 0) cout << data << " ";
    PreOrder(2 * p + 1);
    PreOrder(2 * p + 2);
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int *treeArray = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> treeArray[i];
        }
        BiTree bt;
        bt.CreateTree(treeArray, n);
        bt.PreOrder(0);
        cout << endl;
        delete []treeArray;
    }
    return 0;
}

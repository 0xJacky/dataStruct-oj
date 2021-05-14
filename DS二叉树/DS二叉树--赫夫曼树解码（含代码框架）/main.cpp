//
//  main.cpp
//  DS二叉树--赫夫曼树解码（含代码框架）
//
//  Created by Jacky on 2021/4/27.
//

/*
 题目描述
 已知赫夫曼编码算法和程序，在此基础上进行赫夫曼解码

 在赫夫曼树的类定义中增加了一个公有方法：

     int  Decode(const string codestr, char txtstr[]);    //输入编码串codestr，输出解码串txtstr

 该方法如果解码成功则返回1，解码失败则返回-1，本程序增加宏定义ok表示1，error表示-1

 解码方法的代码框架如下：



 输入
 第一行输入t，表示有t个测试实例
 第二行先输入n，表示第1个实例有n个权值，接着输入n个权值，权值全是小于1万的正整数
 第三行输入n个字母，表示与权值对应的字符
 第四行输入k，表示要输入k个编码串
 第五行起输入k个编码串
 以此类推输入下一个示例

 输出
 每行输出解码后的字符串，如果解码失败直接输出字符串“error”，不要输出部分解码结果

 样例输入
 2
 5 15 4 4 3 2
 A B C D E
 3
 11111
 10100001001
 00000101100
 4 7 5 2 4
 A B C D
 3
 1010000
 111011
 111110111
 样例输出
 AAAAA
 ABEAD
 error
 BBAAA
 error
 DCD
 提示
 */

#include <cstring>
#include <iostream>
#include <string>
#define ok 1
#define error -1
using namespace std;

const int MaxW = 9999999;  // 假设结点权值不超过9999999
// 定义huffman树结点类
class HuffNode {
public:
    int weight;      // 权值
    int parent;      // 父结点下标
    int leftchild;   // 左孩子下标
    int rightchild;  // 右孩子下标
};
// 定义赫夫曼树类
class HuffMan {
private:
    void MakeTree();  // 建树，私有函数，被公有函数调用
    void SelectMin(
        int pos, int *s1,
        int *
            s2);  // 从 1 到 pos 的位置找出权值最小的两个结点，把结点下标存在 s1 和 s2 中
public:
    int len;                         // 结点数量
    int lnum;                        // 叶子数量
    HuffNode *huffTree;              // 赫夫曼树，用数组表示
    char value[800];
    void MakeTree(int n, int wt[], char cd[]);  // 公有函数，被主函数main调用
    void Coding();                   // 公有函数，被主函数main调用
    void Destroy();
    int Decode(const string codestr, char txtstr[]);
};
// 构建huffman树
void HuffMan::MakeTree(int n, int wt[], char cd[]) {
    // 参数是叶子结点数量和叶子权值
    // 公有函数，对外接口
    int i;
    lnum = n;
    len = 2 * n - 1;
    huffTree = new HuffNode[2 * n];
    for (int i = 0; i < n; i++) {
        value[i] = cd[i];
    }
    // huffCode实质是个二维字符数组，第 i 行表示第 i 个字符对应的编码
    // 赫夫曼树huffTree初始化
    for (i = 1; i <= n; i++)
        huffTree[i].weight = wt[i - 1];  // 第0号不用，从1开始编号
    for (i = 1; i <= len; i++) {
        if (i > n) huffTree[i].weight = 0;  // 前n个结点是叶子，已经设置
        huffTree[i].parent = 0;
        huffTree[i].leftchild = 0;
        huffTree[i].rightchild = 0;
    }
    MakeTree();  // 调用私有函数建树
}
void HuffMan::SelectMin(int pos, int *s1, int *s2) {
    // 找出最小的两个权值的下标
    // 函数采用地址传递的方法，找出两个下标保存在 s1 和 s2 中
    int w1, w2, i;
    w1 = w2 = MaxW;  // 初始化w1和w2为最大值，在比较中会被实际的权值替换
    *s1 = *s2 = 0;
    for (i = 1; i <= pos; i++) {
        // 比较过程如下：
        // 如果第 i 个结点的权值小于 w1，且第 i 个结点是未选择的结点，提示：如果第 i 结点未选择，它父亲为 0
        if (huffTree[i].weight < w1 && huffTree[i].parent == 0) {
            // 把第 w1 和 s1 保存到 w2 和 s2，即原来的第一最小值变成第二最小值
            w2 = w1;
            *s2 = *s1;
            // 把第 i 结点的权值和下标保存到 w1 和 s1，作为第一最小值
            w1 = huffTree[i].weight;
            *s1 = i;
        } else {
            // 否则，如果第 i 结点的权值小于 w2，且第 i 结点是未选择的结点
            if (huffTree[i].weight < w2 && huffTree[i].parent == 0) {
                // 把第 i 结点的权值和下标保存到 w2 和 s2，作为第二最小值
                w2 = huffTree[i].weight;
                *s2 = i;
            }
        }
    }
}
void HuffMan::MakeTree() {
    // 私有函数，被公有函数调用
    int i, s1, s2;
    for (i = lnum + 1; i <= len; i++) {
        SelectMin(i - 1, &s1, &s2);  // 找出两个最小权值的下标放入 s1 和 s2 中
        // 将找出的两棵权值最小的子树合并为一棵子树，过程包括
        // 结点 s1 和结点 s2 的父亲设为 i
        huffTree[s1].parent = huffTree[s2].parent = i;
        // 结点 i 的左右孩子分别设为 s1 和 s2
        huffTree[i].leftchild = s1;
        huffTree[i].rightchild = s2;
        // 结点 i 的权值等于 s1 和 s2 的权值和
        huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
    }
}
// 销毁赫夫曼树
void HuffMan::Destroy() {
    len = 0;
    lnum = 0;
    delete[] huffTree;
}

int HuffMan::Decode(const string codestr, char *txtstr) {
    //编码串是codestr，解码结果放在txtstr中
    //编码0表示往左孩子移动，编码1表示往右孩子移动
    int i, k, c;
    char ch = '\0';
    c = len;  //c表示结点数组的下标
    //根结点是结点数组的最后一个结点，所以c一开始指向根结点

    k = 0;  //txtstr的指针
    for (i = 0; i < codestr.length(); i++) {
        //解码流程如下:
        //取编码串的第i个字符放入变量 ch
        ch = codestr[i];
        // 如果ch是字符0，表示往左孩子移动，则c跳转到左孩子
        if (ch == '0') {
            c = huffTree[c].leftchild;
        } else if (ch == '1') {
            // 如果ch是字符1，表示往右孩子移动，则c跳转到右孩子
            c  = huffTree[c].rightchild;
        } else {
            // 如果ch非0非1，表示编码传有错误，返回error表示解码失败
            return error;
        }
        if (huffTree[c].leftchild == 0 && huffTree[c].rightchild == 0) {
            // 如果c指向的节点是否是叶子
            // 解码串txtstr的第k位置保存节点c内的字符
            txtstr[k] = value[c-1];
            k++;
            //c跳回根节点
            c = len;
        } else {
            // 否则
            ch = '\0'; // 设置ch值是用于检查不完成编码的报错
        }
    }
    if (ch == '\0')
        return error;
    else
        txtstr[k] = '\0';  //解码成功，加入字符串结束符
    return ok;
}

// 主函数
int main() {
    int t, n, i, j, k;
    int wt[800];
    char cd[800];
    string huffcode;
    HuffMan myHuff;
    // 1
    cin >> t;
    for (i = 0; i < t; i++) {
        // 2
        cin >> n;
        for (j = 0; j < n; j++) {
            cin >> wt[j];
        }
        // 3
        for (j = 0; j < n; j++) {
            cin >> cd[j];
        }
        // 4
        cin >> k;
        myHuff.MakeTree(n, wt, cd);
        
        // 5
        for (j = 0; j < k; j++) {
            cin >> huffcode;
            
            char *txt = new char[n+1];
            auto err = myHuff.Decode(huffcode, txt);
            if (err == error) {
                cout << "error" << endl;
            } else {
                cout << txt << endl;
            }
            delete [] txt;
        }
    
        myHuff.Destroy();
    }
    return 0;
}

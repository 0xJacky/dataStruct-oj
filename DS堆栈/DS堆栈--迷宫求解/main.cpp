//
//  main.cpp
//  DS堆栈--迷宫求解
//
//  Created by Jacky on 2021/3/24.
//

/*
 题目描述
 给出一个N*N的迷宫矩阵示意图，从起点[0,0]出发，寻找路径到达终点[N-1, N-1]

 要求使用堆栈对象来实现，具体算法参考课本3.2.4节51页

 输入
 第一行输入t，表示有t个迷宫

 第二行输入n，表示第一个迷宫有n行n列

 第三行起，输入迷宫每一行的每个方格的状态，0表示可通过，1表示不可通过

 输入n行

 以此类推输入下一个迷宫

 输出
 逐个输出迷宫的路径

 如果迷宫不存在路径，则输出no path并回车

 如果迷宫存在路径，将路径中每个方格的x和y坐标输出，从起点到终点，每输出四个方格就换行，最终以单词END结尾，具体格式参考示范数据

 输出的代码参考如下：

 //path是保存路径的堆栈，堆栈中每个元素都包含x坐标和y坐标，用属性xp和yp表示

 //path1是一个临时堆栈，把path的数据倒序输出到path1，使得路径按正序输出

     if (!path.empty())    //找到路径

     {    //......若干代码，实现path的数据导入path1

         i=0;  //以下是输出路径的代码

         while (!path1.empty())

         {    cpos = path1.top();

             if ( (++i)%4 == 0 )

                 cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;

             else

                 cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";

             path1.pop();

         }

         cout<<"END"<<endl;

     }

     else

         cout<<"no path"<<endl; //找不到路径输出no path

 样例输入
 2
 8
 0 0 0 1 1 1 1 1
 1 0 0 0 1 0 0 1
 1 0 0 0 1 0 0 0
 1 1 0 0 0 0 0 1
 0 0 1 1 0 1 1 0
 0 0 0 0 0 0 1 1
 1 1 1 1 1 0 0 1
 0 0 0 0 1 0 0 0
 7
 0 0 0 1 1 1 1
 1 0 0 1 0 0 1
 1 0 0 1 0 0 0
 1 1 0 0 0 0 1
 0 0 1 1 0 1 0
 1 0 0 0 0 1 0
 0 0 0 0 1 1 0
 样例输出
 [0,0]--[0,1]--[0,2]--[1,2]--
 [1,3]--[2,3]--[3,3]--[3,4]--
 [4,4]--[5,4]--[5,5]--[6,5]--
 [6,6]--[7,6]--[7,7]--END
 no path
 */

// 参考 https://www.bilibili.com/video/BV1eK411L79V?from=search&seid=2431395396966728281

#include <iostream>
#include <stack>
using namespace std;

typedef struct Point {
    int x;
    int y;
} Point;

stack<Point> path;

// 当前坐标 x, y, 迷宫, 迷宫阶数
bool findPath(int x, int y, int **maze, int limit) {
    // 已有分支到达终点
    if (maze[limit-1][limit-1] == 2) {
        return true;
    }
    // 越界
    if (x < 0 || x >= limit || y < 0 || y >= limit) {
        return false;
    }

    // 判断当前位置是否可走
    if (*(*(maze + x) + y) == 0) {
        // 假设当前路径可走
        *(*(maze + x) + y) = 2;
        // 右下左上
        if (findPath(x, y + 1, maze, limit)
            || findPath(x + 1, y, maze, limit)
            || findPath(x, y - 1, maze, limit)
            || findPath(x - 1, y, maze, limit)
            ) {
            path.push(Point{x, y});
            return true;
        } else {
            *(*(maze + x) + y) = 0;
            return false;
        }
    }
    
    return false;
}

int main() {
    int t, n;
    int **p;
    cin >> t;
    while (t--) {
        cin >> n;
        p = new int*[n];
        for (int i = 0; i < n; i++) {
            p[i] = new int[n];
            for (int j = 0; j < n; j++) {
                cin >> p[i][j];
            }
        }
        findPath(0, 0, p, n);
    
        int x = 0;
        if (!path.empty()) {
            while (!path.empty()) {
                auto point = path.top();
                cout <<'['<< point.x << "," << point.y <<"]--";
                if ((++x)%4 == 0) {
                    cout << endl;
                }
                path.pop();
            }
            cout << "END";
            
        } else {
            cout << "no path";
        }
    
        cout << endl;
        for (int i = 0; i < n; i++) {
            delete p[i];
        }
        delete []p;
    }
    return 0;
}

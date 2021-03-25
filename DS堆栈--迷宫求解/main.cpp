//
//  main.cpp
//  DS堆栈--迷宫求解
//
//  Created by Jacky on 2021/3/24.
//

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

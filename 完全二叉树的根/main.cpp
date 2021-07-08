//
//  main.cpp
//  完全二叉树的根
//
//  Created by Jacky on 2021/7/1.
//

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int t = n * (n - 1) * (n - 2);
    int a[1000][4];
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (a[i][1] == a[j][0] && a[i][0] == a[j][1] && a[i][3] == 1 &&
                a[j][3] == 1) {
                cout << a[i][2] << endl;
                return 0;
            }
        }
    }
    return 0;
}

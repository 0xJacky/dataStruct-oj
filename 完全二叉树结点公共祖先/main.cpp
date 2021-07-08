//
//  main.cpp
//  完全二叉树结点公共祖先
//
//  Created by Jacky on 2021/6/16.
//

#include <iostream>
using namespace std;
 
int main() {
    int m, n;
    while(cin >> m >> n) {
        while (m != n) {
            if (m > n) {
                m /= 2;
            } else {
                n /= 2;
            }
        }
        cout << m << endl;
    }
    return 0;
}

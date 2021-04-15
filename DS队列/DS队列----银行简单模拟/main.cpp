//
//  main.cpp
//  DS队列----银行简单模拟时间限制
//
//  Created by Jacky on 2021/4/7.
//

#include <iostream>
#include <queue>
using namespace std;

queue<int> qA;
queue<int> qB;

int shift(queue<int> &q) {
    int tmp = q.front();
    q.pop();
    return tmp;
}

int main() {
    int n, no;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> no;
        // 奇数
        if (no % 2) {
            qA.push(no);
        } else {
            // 偶数
            qB.push(no);
        }
    }
    int time = 1;
    while (!qA.empty() || !qB.empty()) {
        if (time % 3) {
            if (!qA.empty()) {
                cout << shift(qA);
                if (!qA.empty() || !qB.empty()) {
                    cout << " ";
                }
            }
        } else {
            if (!qB.empty()) {
                cout << shift(qB);
                if (!qA.empty() || !qB.empty()) {
                    cout << " ";
                }
            }
        }
        time++;
    }

    return 0;
}

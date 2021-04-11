//
//  main.cpp
//  DS队列之银行排队
//
//  Created by Jacky on 2021/3/31.
//

#include <iostream>
#include <queue>
using namespace std;

queue<int>qA;
queue<int>qB;
queue<int>qC;

void getAvgTime(queue<int> &q) {
    int i = 0, avg = 0;
    while (!q.empty()) {
        avg += q.front();
        q.pop();
        i++;
    }
    
    avg /= i;
    
    cout << avg << endl;
}

int main() {
    int n, time;
    char type, *p;
    // 1
    cin >> n;
    p = new char[n];
    
    // 2
    for (int i = 0; i < n; i++) {
        cin >> type;
        p[i] = type;
    }
    
    // 3
    for (int i = 0; i < n; i++) {
        cin >> time;
        switch (p[i]) {
            case 'A':
                qA.push(time);
                break;
            case 'B':
                qB.push(time);
                break;
            case 'C':
                qC.push(time);
                break;
            default:
                break;
        }
    }
    
    getAvgTime(qA);
    getAvgTime(qB);
    getAvgTime(qC);
    
    delete []p;
    
    return 0;
}

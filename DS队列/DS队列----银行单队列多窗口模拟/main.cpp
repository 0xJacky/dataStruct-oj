//
//  main.cpp
//  DS队列----银行单队列多窗口模拟
//
//  Created by Jacky on 2021/4/1.
//

#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

typedef struct Customer {
    int t;
    int p;
    int wait;
}Customer;

typedef struct window {
    bool busy;
    int finish;
}Window;

// 排队队列
queue<Customer>q;

int main() {
    int n, t, p, k, global_time = 0, max_wait = 0, finish_time = 0;
    float avg_wait = 0;
    cin >> n;
    // 客户到达时间 T 和事务处理时间 P
    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        q.push({t, p, 0});
    }
    // 银行窗口
    cin >> k;
    auto win = new window[k];
    // 每秒情况
    while (!q.empty()) {
        // 顾客已到
        if (q.front().t <= global_time) {
            // 检查窗口状态
            for (int i = 0; i < k; i++) {
                if (global_time >= win[i].finish) {
                    win[i].busy = false;
                }
            }
            
            for (int i = 0; i < k; i++) {
                if (!win[i].busy && (!q.empty()) && (global_time >= q.front().t)) {
                    win[i].busy = true;
                    q.front().wait = global_time - q.front().t;
                    avg_wait += q.front().wait;
                    win[i].finish = global_time + q.front().p;
                    
                    if (q.front().wait > max_wait) {
                        max_wait = q.front().wait;
                    }
                    if (win[i].finish > finish_time) {
                        finish_time = win[i].finish;
                    }
                    // cout << q.front().t << " " << global_time << " " << q.front().t << " " << q.front().wait << " " << q.front().finish << endl;
                    q.pop();
                }
            }
            
        }
        global_time++;
    }

    avg_wait /= n;
    
    cout << fixed << setprecision(1) << avg_wait << " " << max_wait << " " << finish_time << endl;
    delete [] win;
    return 0;
}

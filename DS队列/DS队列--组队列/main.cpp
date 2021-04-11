//
//  main.cpp
//  DS队列--组队列
//
//  Created by Jacky on 2021/3/31.
//

#include <iostream>
#include <queue>
#include <map>
#include <list>
using namespace std;

int main() {
    int t = 0, n = 0, item;
    string opt;
    cin >> t;
    
    map<int, map<int, bool>> m;
    for (int i = 0; i < t; i++) {
        cin >> n;
        // 组元素存入 map
        for (int j = 0; j < n; j++) {
            cin >> item;
            m[i][item] = true;
        }
    }
    
    queue<int>myQueue;
    list<queue<int>>q;
    
    // 执行操作
    while (opt != "STOP") {
        cin >> opt;
        if (opt == "ENQUEUE") {
            cin >> item;
            
            bool flag = false;
        
            for (auto it = q.begin(); it != q.end(); ++it) {
                if (!it->empty()) {
                    for (int j = 0; j < n; j++) {
                        // 同一组元素已经存在
                        if (m[j][it->front()] && m[j][item]) {
                            it->push(item);
                            flag = true;
                            break;
                        }
                    }
                }
            }
            
            if (!flag) {
                // 列表末尾插入
                queue<int> tmp_queue;
                tmp_queue.push(item);
                q.push_back(tmp_queue);
            }
            
        } else if (opt == "DEQUEUE") {
            while (q.front().empty() && !q.empty()) {
                q.pop_front();
            }
            
            if (!q.empty() && !q.front().empty()) {
                cout << q.front().front() << " ";
                q.front().pop();
            }
            
        }
    }

    return 0;
}

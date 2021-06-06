//
//  main.cpp
//  DS哈希查找与增补
//
//  Created by Jacky on 2021/5/25.
//

#include <iostream>
#include <list>
#include <map>
#define N 11
using namespace std;

class HashTable {
    map<int, list<int>> table;
public:
    void store(int n) {
        table[n%N].push_back(n);
    }
    void search(int n) {
        int count = 0;
        bool flag = false;
        for (auto it = table[n%N].begin(); it != table[n%N].end(); ++it) {
            ++count;
            if (*it == n) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << n%N << ' ' << count << endl;
        } else {
            table[n%N].push_back(n);
            cout << "error" << endl;
        }
    }
};

int main() {
    int n, t;
    cin >> n;
    HashTable table;
    while (n--) {
        cin >> t;
        table.store(t);
    }
    
    cin >> n;
    
    while (n--) {
        cin >> t;
        table.search(t);
    }
    
    return 0;
}

//
//  main.cpp
//  DS堆栈--行编辑
//
//  Created by Jacky on 2021/3/24.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        stack<char> c, o;
        cin >> s;
        auto len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '#') {
                if (!c.empty()) {
                    c.pop();
                }
            } else {
                c.push(s[i]);
            }
        }
        while (!c.empty()) {
            o.push(c.top());
            c.pop();
        }
        if (o.empty()) {
            cout << "NULL";
        } else {
            while (!o.empty()) {
                cout << o.top();
                o.pop();
            }
        }
        cout << endl;
        
    }
    return 0;
}

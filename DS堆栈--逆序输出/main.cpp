//
//  main.cpp
//  DS堆栈--逆序输出
//
//  Created by Jacky on 2021/3/24.
//

#include <iostream>
#include <stack>
using namespace std;
stack<char> c;

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        auto len = s.length();
        for (int i = 0; i < len; i++) {
            c.push(s[i]);
        }
        while (!c.empty()) {
            cout << c.top();
            c.pop();
        }
        cout << endl;
    }
    
    return 0;
}

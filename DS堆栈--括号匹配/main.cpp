//
//  main.cpp
//  DS堆栈--括号匹配
//
//  Created by Jacky on 2021/3/24.
//

#include <iostream>
#include <stack>
using namespace std;

void popTop(stack<char> &c, char a, char b) {
    if (!c.empty() && c.top() == a ) {
        c.pop();
    } else {
        // 没匹配到，丢进去以表失败
        c.push(b);
    }
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        stack<char> c;
        cin >> s;
        auto len = s.length();
        for (int i = 0; i < len; i++) {
            auto & si = s[i];
            if (si == '(') {
                c.push(si);
            } else if (si == ')' ) {
                popTop(c, '(', si);
            } else if (si == '[' ) {
                c.push(si);
            } else if (si == ']' ) {
                popTop(c, '[', si);
            } else if (si == '{' ) {
                c.push(si);
            } else if (si == '}' ) {
                popTop(c, '{', si);
            }
        }
        if (c.empty()) {
            cout << "ok" << endl;
        } else {
            cout << "error" << endl;
        }
    }
    return 0;
}

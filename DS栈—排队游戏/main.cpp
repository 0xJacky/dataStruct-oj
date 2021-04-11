//
//  main.cpp
//  DS栈—排队游戏
//
//  Created by Jacky on 2021/4/7.
//

#include <iostream>
#include <stack>
using namespace std;

typedef struct Child {
    char gender;
    int no;
}Child;

stack<Child>children;

int main() {
    string s;
    cin >> s;
    auto len = s.length();

    for (int i = 0; i < len; i++) {
        if (!children.empty() && children.top().gender != s[i]) {
            cout << children.top().no << " " << i << endl;
            children.pop();
        } else {
            children.push({
                s[i], i
            });
        }
    }
    
    return 0;
}

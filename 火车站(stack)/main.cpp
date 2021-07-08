//
//  main.cpp
//  火车站(stack)
//
//  Created by Jacky on 2021/6/30.
//

#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        stack<char> s;
        int num, i = 0, o = 0;
        string inOrder;
        string outOrder;
        stringstream ss;

        cin >> num >> inOrder >> outOrder;
        while (i < num && o < num) {
            s.push(inOrder[i++]);
            ss << "in" << endl;
            while (!s.empty() && s.top() == outOrder[o]) {
                s.pop();
                o++;
                ss << "out" << endl;
            }
        }
        if (i != num || o != num) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            cout << ss.str();
        }
        cout << "FINISH" << endl;
    }
    return 0;
}

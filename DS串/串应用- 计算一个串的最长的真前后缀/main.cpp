//
//  main.cpp
//  串应用- 计算一个串的最长的真前后缀
//
//  Created by Jacky on 2021/4/14.
//

#include <iostream>
#include <string>
using namespace std;

string matched_Prefix_Postfix(string str) {
    auto length = str.length();
    // 真前缀
    string *pre = new string[length];
    for (int i = 0; i < length - 1; i++) {
        pre[i] = str.substr(0, i + 1);
    }
    // 真后缀
    string *post = new string[length];
    for (int i = 0; i < length - 1; i++) {
        post[i] = str.substr(length - 1 - i, length);
    }
    // 最长真后缀
    string max;
    auto max_length = max.length();

    for (int i = 0; i < length; i++) {
        if (pre[i] == post[i] && pre[i].length() >= max_length) {
            max_length = pre[i].length();
            max = pre[i];
        }
    }

    delete[] pre;
    delete[] post;

    if (max_length) {
        return max;
    }

    return "empty";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << matched_Prefix_Postfix(s) << endl;
    }

    return 0;
}

//
//  main.cpp
//  DS串应用--串替换
//
//  Created by Jacky on 2021/4/14.
//

#include <iostream>
#include <string>
using namespace std;

void get_next(string t, int next[]) {
    int i = 0, j = -1;
    next[i] = j;
    while (i < (int)t.length()) {
        if (j == -1 || t[i] == t[j]) {
            ++i; ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int Index_KMP(string s, string t) {
    int i = 0, j = 0;
    int next[t.length() + 1];
    get_next(t, next);
    while (i < (int)s.length() && j < (int)t.length()) {
        if (j == -1 || s[i] == t[j]) {
            ++i; ++j;
        } else {
            j = next[j];
        }
    }
    if (j == (int)t.length()) {
        return i - j;
    } else {
        return -1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string mainstr;
        string find;
        string replace;
        
        cin >> mainstr >> find >> replace;
        //auto found = mainstr.find(find);
        auto found = Index_KMP(mainstr, find);
        cout << mainstr << endl;
        if (found == -1) {
            cout << mainstr << endl;
        } else {
            // 替换长度相等
            if (find.length() == replace.length()) {
                cout << mainstr.replace(found, replace.length(), replace) << endl;
            } else {
                cout << mainstr.substr(0, found) + replace + mainstr.substr(found + find.length(), string::npos) << endl;
            }
            
        
        }
        
    }
    return 0;
}

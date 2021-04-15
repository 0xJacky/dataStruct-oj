//
//  main.cpp
//  DS串应用—最长重复子串
//
//  Created by Jacky on 2021/4/14.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        auto length = s.length();
        string sub;
        string nosub;
        string ans;
        auto max_length = ans.length();
        for (size_t i = 0; i < length / 2; i++) {
            for (size_t j = 0; j < length - i; j++) {
                sub = s.substr(i, j);
                nosub = s.substr(i + j);
                
                if (nosub.find(sub) != string::npos &&
                    sub.length() >= max_length) {
                    ans = sub;
                    max_length = ans.length();
                }
                
            }
        }
        if (max_length) {
            cout << max_length << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

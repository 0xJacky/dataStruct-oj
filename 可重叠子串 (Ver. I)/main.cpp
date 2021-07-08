//
//  main.cpp
//  可重叠子串 (Ver. I)
//
//  Created by Jacky on 2021/6/30.
//

#include <iostream>
using namespace std;


int main() {
    string s, target;
    int t;
    while (cin >> s) {
        cin >> t;
        while (t--) {
            size_t pos = 0;
            size_t ans = 0;
            cin >> target;
            //s = '%' + s;
            pos = s.find(target);
            while (pos != string::npos) {
                ans++;
                pos = s.find(target, pos + 1);
            }
            cout << target << ':' << ans << endl;
        }
    }
    return 0;
}

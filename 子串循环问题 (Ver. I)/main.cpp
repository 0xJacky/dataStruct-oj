//
//  main.cpp
//  子串循环问题 (Ver. I)
//
//  Created by Jacky on 2021/4/14.
//

/*
 有关子串循环的定理：假设S的长度为len，则S存在最小循环节，循环节的长度L为len-next[len]，子串为S[0…len-next[len]-1]。
 （1）如果len可以被len - next[len]整除，
 则表明字符串S可以完全由循环节循环组成，循环周期T=len/L。
 （2）如果不能，说明还需要再添加几个字母才能补全。
 需要补的个数是循环个数L-len%L=L-(len-L)%L=L-next[len]%L，L=len-next[len]。
 */

#include <iostream>
#include <string>
using namespace std;

long int next_final(string s) {
    string s1, s2;
    auto length = s.length();
    long int max = 0;
    for (long int i = 0; i < length - 1; i++) {
        s1 = s.substr(0, i + 1);
        s2 = s.substr(length - i - 1);
        if (s1 == s2 && i + 1 > max) {
            max = i + 1;
        }
    }
    return max;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        auto len = s.length();
        auto final_next = next_final(s);
        auto l = len - final_next;
        if (len % l == 0 && len != l) {
            cout << 0 << endl;
        } else {
            cout << l - len % l << endl;
        }
    }
    return 0;
}

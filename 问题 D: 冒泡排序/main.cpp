//
//  main.cpp
//  问题 D: 冒泡排序
//
//  Created by Jacky on 2021/6/9.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int data[n];// = new int[n];
        
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }
        
        int ans = 0, tmp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (data[j] > data[j+1]) {
                    tmp = data[j+1];
                    data[j+1] = data[j];
                    data[j] = tmp;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
        
    //delete []data;
    
    return 0;
}

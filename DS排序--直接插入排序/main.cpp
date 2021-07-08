//
//  main.cpp
//  DS排序--直接插入排序
//
//  Created by Jacky on 2021/6/9.
//

#include <iostream>
using namespace std;

void InsertSort(int data[], int length) {
    int i, j;
    for (i = 2; i <= length; ++i) {
        if (data[i] < data[i-1]) {
            data[0] = data[i];
            data[i] = data[i - 1];
            for (j = i - 2; data[0] < data[j]; --j) {
                data[j+1] = data[j];
            }
            data[j+1] = data[0];
        }
        
        
        // print
        for (int k = 1; k <= length; k++) {
            cout << data[k] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int *data = new int[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> data[i];
        }
        InsertSort(data, n);
        delete [] data;
    }
    return 0;
}

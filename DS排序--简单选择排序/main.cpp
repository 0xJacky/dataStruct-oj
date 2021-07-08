//
//  main.cpp
//  DS排序--简单选择排序
//
//  Created by Jacky on 2021/6/16.
//

#include <iostream>
using namespace std;

void PrintArray(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void SelectSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int t = i;
        for (int j = i+1; j < len; j++) {
            if (arr[t] > arr[j]) {
                t = j;
            }
        }
        swap(arr[i], arr[t]);
        PrintArray(arr, len);
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        SelectSort(arr, n);
        cout << endl;
    }
    return 0;
}

//
//  main.cpp
//  DS排序--折半插入排序
//
//  Created by Jacky on 2021/6/16.
//

#include <iostream>
using namespace std;

void PrintArray(int *arr, int len) {
    for (int i = 1; i <= len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}


void BInsertSort(int *arr, int len) {
    for (int i = 2; i <= len; i++) {
        arr[0] = arr[i];
        int low = 1, high = i - 1;
        while (low <= high) {
            int m = (low + high) / 2;
            if (arr[0] > arr[m]) high = m - 1;
            else low = m + 1;
        }
        for (int j = i - 1; j >= high + 1; j--) {
            arr[j+1] = arr[j];
        }
        arr[high+1] = arr[0];
        PrintArray(arr, len);
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        BInsertSort(arr, n);
        cout << endl;
    }
    return 0;
}

//
//  main.cpp
//  DS内排—堆排序
//
//  Created by Jacky on 2021/6/16.
//

#include <iostream>
using namespace std;

void PrintArray(int *arr, int len) {
    cout << len << ' ';
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void HeapAdjust(int *arr, int i, int n) {
    int s;
    while (2*i+1 < n) {
        s = 2*i+1;
        if (s+1<n&&arr[s] > arr[s+1]) s++;
        if (arr[i] > arr[s]) {
            swap(arr[i], arr[s]);
            i = s;
        } else {
            break;
        }
    }
}

void HeapSort(int *arr, int n) {
    int i;
    for (i = n/2; i >= 0; i--) {
        HeapAdjust(arr, i, n);
    }
    PrintArray(arr, n);
    for (i = 1; i < n; i++) {
        swap(arr[0], arr[n-i]);
        HeapAdjust(arr, 0, n - i);
        PrintArray(arr, n);
    }
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    HeapSort(arr, n);
    return 0;
}

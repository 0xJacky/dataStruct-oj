//
//  main.cpp
//  DS排序—快速排序
//
//  Created by Jacky on 2021/6/16.
//

#include <iostream>
using namespace std;

int Partition(int *arr, int low, int high) {
    arr[0] = arr[low];
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) --high;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) ++low;
        arr[high] = arr[low];
    }
    arr[low] = arr[0];
    return low;
}

void QuickSort(int *arr, int low, int high) {
    if (low <= high) {
        int pivot = Partition(arr, low, high);
        cout << arr[pivot] << ' ' << pivot << endl;
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
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
        QuickSort(arr, 1, n);
        cout << endl;
    }
    return 0;
}

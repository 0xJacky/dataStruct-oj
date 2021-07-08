//
//  main.cpp
//  2路归并排序
//
//  Created by Jacky on 2021/6/23.
//

#define MAXN 10001
#include <iostream>
#include <list>
using namespace std;

struct List {
    int data;
    int no;
    bool end;
} a[MAXN], B[MAXN];

list<list<List>> result[MAXN];

void Merge(List A[], int low, int mid, int high) {
    int i, j, k;
    for (k = low; k <= high; k++) {
        B[k] = A[k];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if (B[i].data <= B[j].data) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j++;
        }
    }
    while (i <= mid) {
        A[k] = B[i];
        A[k] = B[i];
        k++;
        i++;
    }
    while (j <= high) {
        A[k] = B[j];
        A[k] = B[j];
        k++;
        j++;
    }
}

void MergeSort(List A[], int low, int high, int level,
               int &resultLevel) {
    if (low < high) {
        int mid = (low + high) / 2;
        level++;
        resultLevel = level;
        MergeSort(A, low, mid, level, resultLevel);
        MergeSort(A, mid + 1, high, level, resultLevel);
        list<List> tmp;
        for (int i = low; i <= high; i++) {
            if (i == mid) {
                A[i].end = true;
            }
            tmp.push_back(A[i]);
            A[i].end = false;
        }
        result[level].push_back(tmp);
        Merge(A, low, mid, high);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].data;
    }
    int level = 0;
    MergeSort(a, 0, n - 1, 0, level);
    cout << 2 * n - 1 << endl;
    for (int i = level + 1; i > 0; i--) {
        while (!result[i].empty()) {
            while (!result[i].front().empty()) {
                cout << result[i].front().front().data << ' ';
                if (result[i].front().front().end) cout << endl;
                result[i].front().pop_front();
            }
            cout << endl;
            result[i].pop_front();
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i].data << ' ';
    }
    cout << endl;
    
    return 0;
}

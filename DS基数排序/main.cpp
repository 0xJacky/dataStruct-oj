//
//  main.cpp
//  DS基数排序
//
//  Created by Jacky on 2021/6/23.
//

#define N 1200
#include <iostream>
#include <list>
using namespace std;

int a[N];
list <int> l[10];

void RadixSortlth(int a[], int n, int ith) {
    for (int i = 0; i < 10; i++) {
        l[i].clear();
    }
    for (int i = 0; i < n; i++) {
        int tmp = a[i];
        for (int j = 0; j < ith; j++) {
            tmp /= 10;
        }
        l[tmp%10].push_back(a[i]);
    }
}

void MoveBack(int a[], list<int>l[]) {
    int j = 0;
    for (int i = 0; i < 10; i++) {
        cout << i << ':';
        if (l[i].empty()) {
            cout << "NULL";
        } else {
            while (!l[i].empty()) {
                a[j++] = l[i].front();
                cout << "->" << l[i].front();
                l[i].pop_front();
            }
            cout << "->^";
        }
        cout << endl;
    }
}

void RadixSort(int a[], int n) {
    int maxa = a[0];
    for (int i = 0; i < n; i++) {
        maxa = maxa > a[i] ? maxa : a[i];
    }
    int maxDigit = 0;
    for (; maxa; maxa /= 10, maxDigit++);
    for (int i = 0; i < maxDigit; i++) {
        RadixSortlth(a, n, i);
        MoveBack(a, l);
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        RadixSort(a, n);
        cout << endl;
    }
    return 0;
}

//
//  main.cpp
//  稳定排序
//
//  Created by Jacky on 2021/6/23.
//

#define MAXN 100001
#include <iostream>
using namespace std;

int a[MAXN][2];
int B[MAXN][2];

void Merge(int A[][2], int low, int mid, int high) {
    int i, j, k;
    for (k = low; k <= high; k++) {
        B[k][0] = A[k][0];
        B[k][1] = A[k][1];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if (B[i][0] <= B[j][0]) {
            A[k][0] = B[i][0];
            A[k][1] = B[i][1];
            i++;
        } else {
            A[k][0] = B[j][0];
            A[k][1] = B[j][1];
            j++;
        }
    }
    while (i <= mid) {
        A[k][0] = B[i][0];
        A[k][1] = B[i][1];
        k++;
        i++;
    }
    while (j <= high) {
        A[k][0] = B[j][0];
        A[k][1] = B[j][1];
        k++;
        j++;
    }
}

void MergeSort(int A[][2], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a[i][0], &a[i][1]);
        }

        MergeSort(a, 0, n - 1);

        for (int i = 0; i < n; i++) {
            printf("%d %d\n", a[i][0], a[i][1]);
        }
    }
    return 0;
}

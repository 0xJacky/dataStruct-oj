//
//  main.cpp
//  DS排序--希尔排序
//
//  Created by Jacky on 2021/6/9.
//

#include <iostream>
using namespace std;

void ShellInsert(
    int data[], int length,
    int dk) {
    //作一趟希尔插入排序
    // 1. 前后记录位置的增量是dk，而不是1;
    // 2. r[0]只是暂存单元，当j<=0时，插入位置已找到。
    int i, j;
    for (i = dk + 1; i <= length; ++i)
        if (data[i] > data[i - dk]) {  // 需要做交换
            data[0] = data[i];         // 暂存在L.r[0]
            for (j = i - dk; j > 0 && (data[0] > data[j]); j -= dk)
                data[j + dk] = data[j];  // 记录后移，查找插入位置
            data[j+dk] = data[0]; // 插入
        }
}  // ShellInsert

void printData(int data[], int len) {
    for (int i = 1; i <= len; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

void ShellSort(
    int data[], int length, string dlta) {
    // 算法10.5 // 按增量序列dlta[0..t-1]对顺序表L作希尔排序。
    for (int k = 0; k < dlta.length(); ++k) {
        ShellInsert(data, length, dlta[k]-'0');
        printData(data, length);
    }
    cout << endl;
    
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        int *data = new int[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> data[i];
        }

        string dlta = "";
        m = n / 2;
        while (m!=1) {
            dlta += (m+'0');
            m /= 2;
        }
        dlta += '1';
        ShellSort(data, n, dlta);
        delete []data;
    }
    
    return 0;
}

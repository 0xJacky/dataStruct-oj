//
//  main.cpp
//  DS静态查找之折半查找
//
//  Created by Jacky on 2021/5/12.
//

#include <iostream>
using namespace std;

int findKey(int v, int d[], int length) {
    int low = 1, high = length, mid;
    while (low <= high) {
        mid = (low+high)/2;
        if (d[mid] == v) return mid;
        else if (v < d[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}


int main() {
    int n, t, *d, v;
    cin >> n;
    d = new int[n+10];
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    
    cin >> t;
    while (t--) {
        cin >> v;
        int r = findKey(v, d, n);
        if (r) cout << r << endl;
        else cout << "error" << endl;
    }
    
    delete [] d;
    
    return 0;
}

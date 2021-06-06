//
//  main.cpp
//  DS哈希查找—线性探测再散列
//
//  Created by Jacky on 2021/5/25.
//

#include <iostream>
#define N 11
using namespace std;

class HashTable {
    int size;
    int *data;
    void store(int n, int hash) {
        hash %= size;
        if (data[hash] == -1) {
            data[hash] = n;
            return;
        }

        if (data[hash + 1] == -1) {
            data[hash + 1] = n;
            return;
        }
        store(n, hash + 1);
    }
    int hash(int n) {
        return n % N;
    }

public:
    HashTable(int n) {
        size = n;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = -1;
        }
    }
    void store(int n) {
        store(n, hash(n));
    }
    void print() {
        for (int i = 0; i < size; i++) {
            if (data[i] != -1) {
                cout << data[i] << ' ';
            } else {
                cout << "NULL ";
            }
        }
        cout << endl;
    }
    void search(int n) {
        int h = hash(n);
        int count = 0;
        while (true) {
            count++;
            h %= size;
            if (data[h] == n) {
                cout << "1 " << count << ' ' << h + 1 << endl;
                break;
            }

            if (data[h] == -1) {
                cout << "0 " << count << endl;
                break;
            }
            h++;
        }
    }
    ~HashTable() {
        delete[] data;
    }
};

int main() {
    int t, n, tmp, size;
    cin >> t;
    while (t--) {
        cin >> size >> n;
        HashTable table(size);
        while (n--) {
            cin >> tmp;
            table.store(tmp);
        }
        table.print();
        cin >> n;
        while (n--) {
            cin >> tmp;
            table.search(tmp);
        }
    }
    return 0;
}

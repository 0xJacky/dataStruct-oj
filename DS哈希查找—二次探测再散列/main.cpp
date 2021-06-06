//
//  main.cpp
//  DS哈希查找—二次探测再散列
//
//  Created by Jacky on 2021/5/31.
//

#include <iostream>
#define N 11
using namespace std;
int sqr(int x) {
    return x * x;
}
class HashTable {
    int size;
    int *data;

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
    void store(int key) {
        if (data[key % 11] == -1) {
            data[key % 11] = key;
        } else {
            int flag = 1;  //1为 +，0为-
            int cnt = 1;
            while (1) {
                int hsNum;
                if (flag == 1) {
                    hsNum = (((key % 11) + sqr(cnt) % size) + size) % size;
                    flag = 0;
                } else {
                    hsNum = (((key % 11) - sqr(cnt) % size) + size) % size;
                    if (hsNum < 0) hsNum *= -1;
                    flag = 1;
                    cnt++;
                }
                if (data[hsNum] == -1) {
                    data[hsNum] = key;
                    break;
                }
            }
        }
    }
    void print() {
        for (int i = 0; i < size - 1; i++) {
            if (data[i] == -1) {
                cout << "NULL ";
            } else {
                cout << data[i] << " ";
            }
        }
        if (data[size - 1] == -1) {
            cout << "NULL" << endl;
        } else {
            cout << data[size - 1] << endl;
        }
    }
    void search(int key) {
        if (data[key % 11] == key) {
            cout << "1 1 " << key % 11 + 1 << endl;
        } else {
            int flag = 1;  //1为 +，0为-
            int cnt = 1;
            int cs = 1;
            while (1) {
                cs++;
                if (cnt == size) {
                    cout << "0 " << size << endl;
                    break;
                }
                int hsNum;
                if (flag == 1) {
                    hsNum = (((key % 11) + sqr(cnt) % size) + size) % size;
                    flag = 0;
                } else {
                    hsNum = (((key % 11) - sqr(cnt) % size) + size) % size;
                    flag = 1;
                    cnt++;
                }
                if (data[hsNum] == key) {
                    cout << "1 " << cs << " " << hsNum + 1 << endl;
                    break;
                }
                if (data[hsNum] == -1) {
                    cout << "0 " << cs << endl;
                    break;
                }
            }
        }
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

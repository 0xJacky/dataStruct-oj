//
//  main.cpp
//  DS内排—2-路归并排序
//
//  Created by Jacky on 2021/6/23.
//

#include <iostream>
using namespace std;

class MyList {
    int n;
    string *nums;
    string *temp;

public:
    MyList(int n) {
        nums = new string[n];
        temp = new string[n];
        this->n = n;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
    }
    void MergeSort() {
        int t = 2;
        while (t < n) t *= 2;
        for (int i = 2; i < t + 1; i *= 2) {
            for (int j = 0; j < n; j += i) {
                int left = j, right = j + i / 2;
                if (right > n) break;
                int middle = right - 1;
                int temp_loc = left;
                while (left <= middle && right < j + i &&
                       right <
                           n)  //根据left,right,middle合并，合并结果存在临时数
                {
                    if (nums[left] > nums[right])  //谁大就把谁放进去
                        temp[temp_loc++] = nums[left++];
                    else
                        temp[temp_loc++] = nums[right++];
                }
                while (left <= middle)  //把剩余的也存进去
                    temp[temp_loc++] = nums[left++];
                while (right < j + i && right < n)  //把剩余的也存进去
                    temp[temp_loc++] = nums[right++];
                for (int m = j; m < j + i && m < n;
                     m++)  //将临时存的合并结果存回原数组
                {
                    nums[m] = temp[m];
                }
            }

            Print();
        }
    }
    void Print() {
        for (int i = 0; i < n; i++) {
            cout << nums[i] << ' ';
        }
        cout << endl;
    }
    ~MyList() {
        delete[] nums;
        delete[] temp;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        MyList list(n);
        list.MergeSort();
        cout << endl;
    }
    return 0;
}

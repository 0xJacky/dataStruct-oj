//
//  main.cpp
//  动态数组
//
//  Created by Jacky on 2021/3/4.
//

/*
题目描述
一开始未知数组长度，根据要求创建不同类型的指针，并且使用指针创建相应长度的数组，然后再完成不同的要求

若要求创建整数数组，计算数组内所有数据的平均值

若要求创建字符数组，找出数组内的最大字母

若要求创建浮点数数组，找出数组的最小值

要求程序整个过程不能使用数组下标，从数组创建、输入到搜索、比较、计算，到输出都必须使用指针

提示：使用new关键字

输入
第一行输入t表示有t个测试实例

第二行先输入一个大写字母表示数组类型，I表示整数类型，C表示字符类型，F表示浮点数类型；然后输入n表示数组长度。

第三行输入n个数据

依次输入t个实例

输出
每个根据不同的数组类型输出相应的结果

样例输入
3
C 5
A D E B C
I 6
22 55 77 33 88 55
F 4
3.1 1.9 6.5 4.8
样例输出
E
55
1.9
提示
*/

#include <iostream>
using namespace std;

template <typename T>
void getInput(T* a, int& length) {
    for (int i = 0; i < length; i++) {
        cin >> *(a + i);
    }
}

int avg(int* a, int &length) {
    int avg = 0;
    for (int i = 0; i < length; i++) {
        avg += *(a + i);
    }
    avg /= length;
    return avg;
}

char max(char* a, int& length) {
    char ans = 0;
    for (int i = 0; i < length; i++) {
        if (*(a + i) > ans) ans = *(a + i);
    }
    return ans;
}

float min(float* a, int& length) {
    float ans = *a;
    for (int i = 1; i < length; i++) {
        if (*(a + i) < ans) ans = *(a + i);
    }
    return ans;
}

int main() {
    int t, n;
    char type;
    cin >> t;
    while (t--) {
        cin >> type >> n;
        if (type == 'I') {
            int* int_array = new int[n];
            getInput(int_array, n);
            cout << avg(int_array, n) << endl;
            delete[] int_array;
        }
        else if (type == 'C') {
            char* char_array = new char[n];
            getInput(char_array, n);
            cout << max(char_array, n) << endl;
            delete[] char_array;
        }
        else if (type == 'F') {
            float* float_array = new float[n];
            getInput(float_array, n);
            cout << min(float_array, n) << endl;
            delete[] float_array;
        }
    }

    return 0;
}

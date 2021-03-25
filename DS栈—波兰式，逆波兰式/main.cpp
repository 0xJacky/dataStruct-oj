//
//  main.cpp
//  DS栈—波兰式，逆波兰式
//
//  Created by Jacky on 2021/3/24.
//

#include <cstring>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

map<char, int> priority = {{'*', 2}, {'/', 2}, {'+', 1},
                           {'-', 1}, {'(', 0}, {')', 0}};

void reservePolish(string s) {
    // 运算符
    stack<char> opt;
    auto len = s.length();
    bool firstNum = true;
    bool lastNum = false;
    
    for (int i = 0; i < len; i++) {
        char &c = s[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            // 若遇到运算符，
            // 若该运算符优先级大于栈顶运算符的优先级时，则把它压栈
            if (opt.empty() || opt.top() == '(') {
                opt.push(c);
            } else {
                // 若该运算符的优先级小于等于栈顶运算符时，将栈顶运算符弹出并输出，
                // 再比较新的栈顶运算符，按同样处理方法，直到该运算符大于栈顶运算符的优先级为止
                while (!opt.empty() && priority[opt.top()] >= priority[c]) {
                    if (!firstNum) {
                        cout << " ";
                    }
                    cout << opt.top();
                    opt.pop();
                }
                // 然后将该运算符压栈
                opt.push(c);
            }
            lastNum = false;
            firstNum = false;

        } else if (c == '(') {
            // 若遇到左括号，压入堆栈
            opt.push(c);
            lastNum = false;

        } else if (c == ')') {
            // 若遇到右括号，将栈顶运算符弹出并输出，直到遇到左括号
            while (!opt.empty()) {
                if (opt.top() == '(') {
                    opt.pop();
                    break;
                }
                
                if (!firstNum) {
                    cout << " ";
                }
                
                cout << opt.top();
                opt.pop();
            }
            lastNum = false;
            firstNum = false;
            
        } else if (isalnum(c)) {
            // 若遇到运算数，则直接输出
            if (firstNum || lastNum) {
                cout << c;
            } else {
                cout << " " << c;
            }
            lastNum = true;
            firstNum = false;
        }
        // 如果遇到空格或其他字符不处理
    }
    while (!opt.empty()) {
        if (!firstNum) {
            cout << " ";
        }
        cout << opt.top();
        opt.pop();
    }
    cout << endl;
}

// 从后往前扫描表达式，) 和 ( 互换，栈顶运算符优先级>新读入运算符优先级出栈，逆序输出
void polish(string s) {
    // 运算符
    stack<char> opt;
    // 输出栈
    stack<char> output;
    
    bool lastNum = false;

    auto len = s.length();
    for (long int i = len - 1; i >= 0; i--) {
        char c = s[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            // 若遇到运算符，
            // 若该运算符优先级大于栈顶运算符的优先级时，则把它压栈
            if (opt.empty() || opt.top() == ')') {
                opt.push(c);
            } else {
                // 教材第三章表3.1中的相同运算符优先级>（从左往右计算）改为<，
                // 例如栈顶为‘+‘，新读入的为‘+’，则栈顶优先级<新读入的优先级。
                while (!opt.empty() && priority[opt.top()] > priority[c]) {
                    output.push(' ');
                    output.push(opt.top());
                    opt.pop();
                }
                // 然后将该运算符压栈
                opt.push(c);
            }
           

        } else if (c == ')') {
            opt.push(c);
        } else if (c == '(') {
            
            while (!opt.empty()) {
                if (opt.top() == ')') {
                    opt.pop();
                    break;
                }
                
                output.push(' ');
                output.push(opt.top());
                opt.pop();
            }
            
        } else if (isalnum(c)) {
            // 若遇到运算数，则直接输出
            if (!lastNum) {
                output.push(' ');
            }
            output.push(c);
        }
        lastNum = isalnum(c);
        // 如果遇到空格或其他字符不处理
    }
    while (!opt.empty()) {
        output.push(' ');
        output.push(opt.top());
        opt.pop();
    }
    // 倒叙输出
    while (!output.empty()) {
        char &ch = output.top();
        
        if (ch == ' ') {
            output.pop();
            if (output.empty()) {
                cout << endl;
                break;
            } else {
                cout << " ";
                continue;
            }
        }
        cout << ch;
        output.pop();
    }
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        polish(s);
        reservePolish(s);
        cout << endl;
    }
    return 0;
}

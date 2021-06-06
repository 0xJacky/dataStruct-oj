//
//  main.cpp
//  DS哈希查找--Trie树
//
//  Created by Jacky on 2021/5/31.
//

#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

class Node {
public:
    char data = '0';
    int count = 0;
    Node *next[26];
    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Trie {
    void LevelOrder(Node *t) {
        queue<Node *> tq;
        for (int i = 0; i < 26; i++) {
            if (t[i].data != '0') {
                tq.push(&t[i]);
            }
        }
        while (!tq.empty()) {
            Node *t = tq.front();
            tq.pop();
            cout << t->data;
            for (int i = 0; i < 26; i++) {
                if (t->next[i] != NULL) {
                    tq.push(t->next[i]);
                }
            }
        }

        cout << endl;
    }

public:
    Node *root;
    Trie() {
        root = new Node[26];
    }
    void LevelOrder() {
        LevelOrder(root);
    }
};

int main() {
    Trie trie;
    int t;
    string s;
    stringstream ss;
    getline(cin, s);
    ss << s;

    string tmp;
    while (ss >> tmp) {
        auto p = trie.root;
        p[tmp[0] - 'a'].data = tmp[0];
        p[tmp[0] - 'a'].count++;
        p = &p[tmp[0]- 'a'];
        for (int i = 1; i < tmp.length(); i++) {
            if (p->next[tmp[i] - 'a'] != NULL) {
                p->next[tmp[i] - 'a']->count++;
                p = p->next[tmp[i] - 'a'];
                continue;
            }
            Node *tempNode = new Node;
            tempNode->data = tmp[i];
            tempNode->count++;
            p->next[tmp[i] - 'a'] = tempNode;
            p = p->next[tmp[i] - 'a'];
        }
    }
    trie.LevelOrder();
    cin >> t;
    while (t--) {
        cin >> tmp;
        auto p = trie.root;
        bool flag = true;
        if (p[tmp[0] - 'a'].data == '0') {
            flag = false;
        }
        p = &p[tmp[0]-'a'];
        for (int i = 1; i < tmp.length() && flag; i++) {
            if (p->next[tmp[i] - 'a']) {
                p = p->next[tmp[i] - 'a'];
            } else {
                flag = false;
            }
        }
        if (flag && p) {
            cout << p->count << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}

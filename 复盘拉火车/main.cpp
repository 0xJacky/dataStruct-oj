//
//  main.cpp
//  复盘拉火车
//
//  Created by Jacky on 2021/6/30.
//

#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

void print(list <string> l) {
    for (string s : l) {
        cout << ' ' << s;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        list<string> deck, GJ, XS;
        string c;
        cin >> n;
        while (n--) {
            cin >> c;
            GJ.push_back(c);
        }
        cin >> n;
        while (n--) {
            cin >> c;
            XS.push_back(c);
        }
        cin >> n;
        
        bool flag = true;
        while (n--) {
            if (flag) {
                deck.push_back(GJ.front());
                GJ.pop_front();
            } else {
                deck.push_back(XS.front());
                XS.pop_front();
            }
    
            // find
            auto end = deck.end();
            auto pos = find(deck.begin(), --end, deck.back());
           
            if (pos != end) {
                list <string> tmp;
                tmp.splice(tmp.begin(), deck, pos, deck.end());
                
                if (pos == deck.begin()) {
                    deck.clear();
                }
                
                if (flag) {
                    GJ.insert(GJ.end(), tmp.begin(), tmp.end());
                } else {
                    XS.insert(XS.end(), tmp.begin(), tmp.end());
                }
            }
            
            flag = !flag;
        }
        cout << "Deck:";
        print(deck);
        cout << "GJ:";
        print(GJ);
        cout << "XS:";
        print(XS);
        cout << endl;
    }

    return 0;
}

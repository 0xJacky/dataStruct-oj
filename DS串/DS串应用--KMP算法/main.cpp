#include <iostream>
#include <string>
using namespace std;
 
class myString {
private:
    string mainstr;
    long int size;
     
    void GetNext(string p, int next[]);
    int KMPFind(string p, int pos, int next[]);
public:
    myString();
    ~myString();
    void SetVal(string sp);
    long int KMPFindSubstr(string p, int pos);
};
 
myString::myString() {
    size = 0;
    mainstr = "";
}
 
myString::~myString() {
    size = 0;
    mainstr = "";
}
 
void myString::GetNext(string p, int next[]) {
    int i = 0, j = -1;
    next[i] = j;
    auto length = p.length();
    while (i < length) {
        if (j == -1 || p[i] == p[j]) {
            ++i; ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}
 
int myString::KMPFind(string p, int pos, int next[]) {
    int i = 0, j = 0;
    int length = (int)p.length();
 
    while (i < size && j < length) {
        if (j == -1 || mainstr[i] == p[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == length) {
        return i - j + 1;
    }
    return 0;
}

void myString::SetVal(string sp) {
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}
 
long int myString::KMPFindSubstr(string p, int pos) {
    auto L = p.length();
    auto *next = new int[L];
    GetNext(p, next);
    for (auto i = 0; i < L; i++) {
        cout << next[i] << ' ';
    }
    cout << endl;
    int v = -1;
    v = KMPFind(p, pos, next);
     
    delete []next;
     
    return v;
}
 
 
int main() {
    int t;
    string main, pattern;
    cin >> t;
     
    while (t--) {
        cin >> main >> pattern;
        myString s;
        s.SetVal(main);
        cout << s.KMPFindSubstr(pattern, 0) << endl;
    }
     
    return 0;
}

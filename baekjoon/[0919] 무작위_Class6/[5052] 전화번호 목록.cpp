#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
struct Trie {//트라이 구조
    Trie* next[10];
    bool finish;
    bool nextchild;
    Trie() {
        nextchild = 0;
        finish = 0;
        for (int i = 0; i < 10; i++) {
            next[i] = 0;
        }
    }
    ~Trie() {
        for (int i = 0; i < 10; i++) {
            if (next[i]) {
                delete next[i];
            }
        }
    }
    void insert(char* s) {
        if (*s == '\n')
            finish = true;
        else {
            int n = *s - '0';
            if (!next[n]) next[n] = new Trie;
            nextchild = true;
            next[n]->insert(s + 1);
        }
    }

    bool consistent() {
        if (nextchild && finish) return false;
        for (int i = 0; i < 10; i++) {
            if (next[i] && !next[i]->consistent()) return false;
        }
        return true;
    }
};
int T, N;
vector<pair<int, int>> v;
vector<string> s;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        string temp;
        Trie* root = new Trie;//루트 포인터??
        FOR(i, 0, N) {
            cin >> temp;
            char* c = new char[temp.size()+1];
            for (int i = 0; i < temp.size(); i++) {
                c[i] = temp[i];
            }
            c[temp.size()] = '\n';
            root->insert(c);
        }
        if (!root->consistent())
            cout << "NO\n";
        else
            cout << "YES\n";
        delete root;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define alpha 26
int N;
struct Trie {//TRIE
    map<string, Trie> child;//if use Trie[alphabet] 
    //case like (A->ABC, A->A), (A->BANANA, A->BANANANI) distinction is hard, so use string map!! 
    void insert(Trie &t, vector<string> &v, int idx) {//root, string vector, 0
        if (idx == v.size())
            return;
        if (t.child.find(v[idx]) == t.child.end()) {
            t.child[v[idx]] = Trie();// not * -> not new!!
        }
        insert(t.child[v[idx]], v, idx + 1);//insert() is member func, but don't need var except paramiter
        //so don't have to object.insert()
    }
    void search(int lev) {
        for (auto iter = child.begin(); iter != child.end(); iter++) {
            for (int i = 0; i < lev; i++)
                cout << "--";
            cout << iter->first << "\n";
            iter->second.search(lev + 1);
        }
    }
};
int main() {
    FASTIO;
    cin >> N;
    int M;
    Trie root;
    for (int i = 0; i < N; i++) {
        cin >> M;
        string tempstr;
        vector<string> str;
        for (int j = 0; j < M; j++) {
            cin >> tempstr;
            str.push_back(tempstr);//str = {A, B, C, D} A->B->C->D
            root.insert(root, str, 0);
        }
    }
    root.search(0);//start with level 0
    return 0;
}
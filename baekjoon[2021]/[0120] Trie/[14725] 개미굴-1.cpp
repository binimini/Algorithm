#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define alpha 26
int N;
struct Trie {//TRIE original?
    Trie* next[alpha];
    bool wordend;
    Trie() {
        for (int i = 0; i < alpha; i++)
            next[i] = nullptr;//pointer intialization as null
        wordend = false;
    }
    ~Trie() {
        for (int i = 0; i < alpha; i++) {
            if (next[i])//if null, is false
                delete next[i];
        }
    }
    void insert(const char* key) {
        if (*key == '\0') {
            wordend = 1;
            return;
        }
        int nextkey = *key - 'A';
        if (!next[nextkey]) {
            next[nextkey] = new Trie();
        }
        next[nextkey]->insert(key + 1);
    }
    void search(int level) {
        string lev = "";
        for (int i = 0; i < level + 1; i++)
            lev += "--";
        if (wordend) {
            cout << '\n';
        }
        for (int i = 0; i < alpha; i++) {
            if (next[i]) {
                if (wordend)//before nextword, print level
                    cout << lev;
                cout << char('A' + i);//next char
                //recursive next[i]->search();
                if (wordend)
                    next[i]->search(level + 1);//if word ends, level increases
                else
                    next[i]->search(level);//word continues
            }
        }
    }
};
int main() {
    /* this version of Trie Algorithm hard to manage case like {{A, ABC}, {A, A}}, {{BANANA, BANANA}, {BANANA, BANANANA}}
    because Trie Algorithm decides A(end)-A(end)-B-C(end) => A--A----BC (correct : A--A--ABC)
    B-A-N-A-N-A(end)-B-A-N-A-N-A(end)-N-A(end) => BANANA--BANANA----NA (correct : BANANA--BANANA--BANANANA)
            */
    FASTIO;
    cin >> N;
    int M;
    Trie root;
    for (int i = 0; i < N; i++) {
        cin >> M;
        string str = "", tempstr;
        for (int j = 0; j < M; j++) {
            cin >> tempstr;
            str += tempstr;//APPLE KIWI -> tempstr ="KIWI", str = "APPLEKIWI"
            root.insert(str.c_str());//c_str() : string -> const char*!!
        }
    }
    root.search(0);//start with level 0
    return 0;
}
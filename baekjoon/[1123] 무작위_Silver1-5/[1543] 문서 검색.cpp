#include <bits/stdc++.h>
using namespace std;
string docu, word;
bool check(int idx) {
    for (int i = 0; i < word.size(); i++) {
        if (docu[idx + i] != word[i])
            return false;
    }
    return true;
}
int main() {
    int cnt = 0;
    getline(cin, docu);
    getline(cin, word);
    for (int i = 0; i < docu.size(); i++) {
        if (word[0] == docu[i]&& i+word.size()-1<=docu.size()-1) {
            if (check(i)) {
                i = i + word.size()-1;
                cnt++;
            }
            else
                continue;
        }
    }
    cout << cnt;
    return 0;
}
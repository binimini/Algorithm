#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
int q, str[200000][26] = { 0 };
int main() {
    FASTIO;
    cin >> s;
    str[0][s[0] - 'a']++;
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            str[i][j] += str[i - 1][j];
        }
        str[i][s[i] - 'a']++;
    }
    cin >> q;
    char temp;
    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> temp >> l >> r;
        if (l != 0)
            cout << str[r][temp - 'a'] - str[l - 1][temp - 'a'] << "\n";
        else
            cout << str[r][temp - 'a'] << "\n";
    }
    return 0;
}
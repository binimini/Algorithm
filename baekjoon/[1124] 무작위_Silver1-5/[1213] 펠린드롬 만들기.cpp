#include <bits/stdc++.h>
using namespace std;
string s;
int Alpha[26] = { 0 };
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        Alpha[s[i] - 'A']++;
    }
    pair<int, int> odd = { 0,0 };
    for (int i = 0; i < 26; i++) {
        if (Alpha[i] % 2 != 0)
            odd.first++, odd.second = i, Alpha[i]--;
    }
    if (odd.first <= 1) {
        string result = "";
        for (int i = 0; i < 26; i++) {
            while (Alpha[i] != 0) {
                cout << (char)(i + 'A');
                result += (i + 'A');
                Alpha[i] -= 2;
            }
        }
        if (odd.first)
            cout << (char)(odd.second + 'A');
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i];
        }
    }
    else
        cout << "I'm Sorry Hansoo";
    return 0;
}
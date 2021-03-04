#include <bits/stdc++.h>
using namespace std;
string s;
map<string, int> m;
int main() {
    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j <= s.size() - i; j++) {
            m[s.substr(j, i)] = 1;
        }
    }
    cout << m.size();
    return 0;
}
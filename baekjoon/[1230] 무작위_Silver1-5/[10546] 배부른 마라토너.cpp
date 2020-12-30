#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;
map<string, int> m;
int main() {
    FASTIO;
    cin >> N;
    string name;
    for (int i = 0; i < N; i++) {
        cin >> name;
        if (m.find(name) == m.end())
            m[name] = 1;
        else
            m[name]++;
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> name;
        m[name]--;
    }
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second != 0)
            cout << iter->first;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, res = 0;
map<string, int> m;
int main() {
    FASTIO;
    cin >> N >> M;
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        m[temp] = 1;
    }
    for (int j = 0; j < M; j++) {
        cin >> temp;
        if (m.find(temp) != m.end()) {
            res++;
            m[temp]++;
        }
    }
    cout << res << "\n";
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == 2)
            cout << iter->first << "\n";
    }
    return 0;
}
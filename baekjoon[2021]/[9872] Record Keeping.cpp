#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;
string temp;
vector<string> v;
map<string, int> m;
int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        v.clear();
        for (int j = 0; j < 3; j++) {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        m[v[0] + v[1] + v[2]]++;
    }
    int ans = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        ans = max(ans, iter->second);
    }
    cout << ans;
    return 0;
}
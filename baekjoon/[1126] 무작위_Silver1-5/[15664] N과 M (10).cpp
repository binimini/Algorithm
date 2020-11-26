#include <bits/stdc++.h>
using namespace std;
int N, M, c[8] = { 0 }, arr[8];
vector<int> v;
map<int, int> m;
void dfs(int node, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = node; i < m.size(); i++) {
        if (c[i] >= m[v[i]]) continue;
        arr[cnt] = v[i];
        c[i]++;
        dfs(i, cnt + 1);
        c[i]--;
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (m.find(temp) == m.end()) {
            m[temp] = 1;
            v.push_back(temp);
        }
        else
            m[temp]++;
    }
    sort(v.begin(), v.end());
    dfs(0,0);
    return 0;
}
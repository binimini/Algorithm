#include <bits/stdc++.h>
using namespace std;
set<int> s;
int N, M, arr[8];
vector<int> v;
void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            cout << arr[i]<<" ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        arr[cnt] = v[i];
        dfs(cnt + 1);
    }
}
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (s.find(temp) == s.end())
            s.insert(temp);
    }
    for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
        v.push_back(*iter);
    }
    dfs(0);
    return 0;
}
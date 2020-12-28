#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, cnt = 0;
vector<int> e[100], r_e[100];
bool v[100] = { 0 }, visited[100] = { 0 };
void dfs(vector<int> e[], int node) {
    for (int i = 0; i < e[node].size(); i++) {
        if (visited[e[node][i]]) continue;
        visited[e[node][i]] = 1;
        cnt++;
        dfs(e, e[node][i]);
    }
}
int main() {
    FASTIO;
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        e[b].push_back(a);
        r_e[a].push_back(b);
    }
    for (int i = 1; i <= N; i++) {
        for (int i = 1; i <= N; i++) 
            visited[i] = 0;
        cnt = 0;
        visited[i] = 1;
        dfs(e, i);
        if (cnt > N / 2)
            v[i] = 1;
        for (int i = 1; i <= N; i++) 
            visited[i] = 0;
        cnt = 0;
        visited[i] = 1;
        dfs(r_e, i);
        if (cnt > N / 2 )
            v[i] = 1;
    }
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (v[i])
            result++;
    }
    cout << result;
    return 0;
}
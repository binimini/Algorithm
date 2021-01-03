#include <bits/stdc++.h>
using namespace std;
int N, M, K;
bool visited[1001] = { 0 };
vector<int> edge[1001];
int AbyB[1001] = { 0 };
int matched[1001] = { 0 };
bool dfs(int node) {
    if (visited[node]) return 0;
    visited[node] = 1;
    int cnt = 0;
    for (int i = 0; i < edge[node].size(); i++) {
        int b = edge[node][i];
        if (AbyB[b] == 0 || dfs(AbyB[b])) {
            AbyB[b] = node;
            return 1;
        }
    }
    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    int size, temp;
    for (int i = 1; i <= N; i++) {
        cin >> size;
        for (int j = 0; j < size; j++) {
            cin >> temp;
            edge[i].push_back(temp);
        }
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visited[j] = 0;
        }
        if (dfs(i))
            res++;
    }
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (count == K)
            break;
        for (int j = 1; j <= M; j++) {
            visited[j] = 0;
        }
        if (dfs(i)) {
            count++;
            res++;
        }
    }
    cout << res;
    return 0;
}
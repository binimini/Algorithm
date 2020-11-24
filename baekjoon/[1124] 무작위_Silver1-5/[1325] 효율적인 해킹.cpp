#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> e[10001];
queue<int> q;
bool visited[10001] = { 0 };
pair<int, vector<int>> result;
int bfs() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size(); i++) {
            if (visited[e[x][i]]) continue;
            visited[e[x][i]] = 1;
            q.push(e[x][i]);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            cnt++;
            visited[i] = 0;
        }
    }
    return cnt;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int A, B;
    result.first = 0;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        e[B].push_back(A);
    }
    int R;
    for (int i = 1; i <= N; i++) {
        q.push(i);
        visited[i] = 1;
        R = bfs();
        if (R >= result.first) {
            if (R > result.first) {
                result.second.clear();
                result.first = R;
            }
            result.second.push_back(i);
        }
    }
    sort(result.second.begin(), result.second.end());
    for (int i = 0; i < result.second.size(); i++) {
        cout << result.second[i] << " ";
    }
    return 0;
}
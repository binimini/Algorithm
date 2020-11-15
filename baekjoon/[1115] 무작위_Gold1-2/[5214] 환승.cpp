#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N, K, M;
queue<int> q;
vector<int> tube[1000];
vector<int> vtotube[100001];
int visited[100001];
int bfs() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == N)
            return visited[x];
        for (int i = 0; i < vtotube[x].size(); i++) {
            int t = vtotube[x][i];
            for (int j = 0; j < tube[t].size(); j++) {
                if (visited[tube[t][j]]) continue;
                visited[tube[t][j]] = visited[x] + 1;
                if (tube[t][j] == N)
                    return visited[N];
                q.push(tube[t][j]);
            }
        }
    }
    return -1;
}
int main() {
    cin >> N >> K >> M;
    int temp;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> temp;
            tube[i].push_back(temp);
            vtotube[temp].push_back(i);
        }
    }
    q.push(1);
    visited[1] = 1;
    cout << bfs();
    return 0;
}
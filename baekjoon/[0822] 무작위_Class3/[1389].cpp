#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int visited[101] = { 0 };
vector<int> edge[101];
queue<int> q;
int value = 0;
void BFS() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < edge[x].size(); i++) {
            if (visited[edge[x][i]]) continue;
            visited[edge[x][i]] = visited[x] + 1;
            value += visited[x];
            q.push(edge[x][i]);
        }
    }
}
int main() {//케빈 베이컨의 6단계 법칙
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    pair<int, int> result = { 101,0 };
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[j] = 0;
        }
        value = 0;
        visited[i] = 1;
        q.push(i);
        BFS();
        if (value < result.first)
            result.first = value, result.second = i;
    }
    cout << result.second << '\n';
    return 0;
}
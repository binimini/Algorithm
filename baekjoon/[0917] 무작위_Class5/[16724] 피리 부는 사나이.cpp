#include <bits/stdc++.h>
using namespace std;
int N, M, cnt = 0, result = 0;
char mapp[1000][1000];
int visited[1000][1000] = { 0 };
void DFS(int i, int j) {
    if (visited[i][j]) {
        if (visited[i][j] < cnt)
            result--;
        return;
    }
    visited[i][j] = cnt;
    if (mapp[i][j] == 'U')
        DFS(i - 1, j);
    else if (mapp[i][j] == 'D')
        DFS(i + 1, j);
    else if (mapp[i][j] == 'L')
        DFS(i, j - 1);
    else if (mapp[i][j] == 'R')
        DFS(i, j + 1);
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mapp[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue;
            result++;
            cnt++;
            DFS(i,j);
        }
    }
    cout << result << "\n";
    return 0;
}